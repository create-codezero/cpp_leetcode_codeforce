/*
Concepts Used to solve this question:

1. Sliding Window Technique:
   - A dynamic window is maintained using two pointers (left and right).
   - The window expands to include required characters and shrinks to minimize size.

2. Frequency Counting:
   - Character frequencies of string t are stored.
   - A running frequency map tracks characters inside the current window.

3. Window Validity Tracking:
   - A window is considered valid when it contains all required characters
     with at least the required frequency.
   - Instead of comparing maps, a counter tracks how many characters
     meet the required frequency.

4. Greedy Window Shrinking:
   - Once the window becomes valid, we try shrinking it from the left
     to find the smallest valid window.
   - Shrinking stops when validity is lost.

5. Incremental Update Strategy:
   - Window expansion and contraction update frequencies incrementally.
   - This avoids recomputing counts repeatedly.

*/

/*
Data Structures Used to solve this question:

1. unordered_map<char, int> tMap:
   - Stores frequency of each character required from string t.

2. unordered_map<char, int> currMap:
   - Stores frequency of characters in the current sliding window.

3. int left, right:
   - Two pointers defining the current window boundaries.

4. int required:
   - Number of unique characters required to form a valid window.

5. int formed:
   - Number of characters that currently meet the required frequency.

6. vector<int> lastWindow:
   - Stores the start and end indices of the minimum valid window found.

*/

/*
Optimizations Used to solve this question:

1. Linear Time Complexity:
   - Each character is processed at most twice (once by left, once by right).
   - Overall time complexity is O(n).

2. Constant Extra Space:
   - Only fixed-size hash maps are used (bounded by character set).
   - Space complexity is O(1).

3. Avoiding Full Map Comparison:
   - Instead of comparing frequency maps, a counter is used to track validity.
   - This significantly improves performance.

4. Efficient Greedy Shrinking:
   - Window shrinking is performed only when the window is valid.
   - Guarantees the smallest possible valid window is found.

*/

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> tMap;
        for (char c : t) {
            tMap[c]++;
        }

        unordered_map<char, int> currMap;

        int required = tMap.size();
        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        vector<int> lastWindow(2, -1);

        for (int right = 0; right < s.size(); right++) {

            // Expand window
            if (tMap.count(s[right])) {
                currMap[s[right]]++;
                if (currMap[s[right]] == tMap[s[right]]) {
                    formed++;
                }
            }

            // Shrink window when valid
            while (left <= right && formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    lastWindow[0] = left;
                    lastWindow[1] = right;
                }

                if (tMap.count(s[left])) {
                    currMap[s[left]]--;
                    if (currMap[s[left]] < tMap[s[left]]) {
                        formed--;
                    }
                }
                left++;
            }
        }

        if (lastWindow[0] == -1) return "";
        return s.substr(lastWindow[0], minLen);
    }
};
