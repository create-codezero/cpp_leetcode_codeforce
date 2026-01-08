/*
Concepts Used to solve this question:

1. Sliding Window Technique:
   - Instead of checking every possible substring from scratch, the algorithm maintains
     a moving window over the string `s`.
   - The window slides in steps of `wordLen`, allowing reuse of previously computed data.
   - This avoids repeated recomputation and reduces time complexity from O(n × m) to O(n).

2. Fixed-Length Chunking:
   - All words have the same length (`wordLen`).
   - The string `s` is processed in chunks of size `wordLen`, ensuring proper word alignment.
   - Multiple passes are made with different starting offsets (0 to wordLen − 1).

3. Frequency Matching:
   - The problem requires matching exact frequencies of words.
   - A reference frequency map (`freq`) stores how many times each word must appear.
   - A temporary frequency map (`tempFreq`) tracks words in the current window.

4. Window Shrinking Strategy:
   - If a word appears more times than allowed, the window is shrunk from the left.
   - This ensures the window always represents a valid partial solution.
   - Shrinking continues until the word frequency becomes valid again.

5. Early Termination / Guard Conditions:
   - If the total length of all words exceeds the length of `s`, the function returns early.
   - Invalid words immediately reset the window, preventing unnecessary processing.

6. Hash-Based Lookups:
   - Unordered maps are used for O(1) average-time lookups and updates.
   - This is critical for maintaining efficiency under large inputs.

*/

/*
Data Structures Used to solve this question:

1. unordered_map<string, int> freq:
   - Stores the required frequency of each word from the `words` list.
   - Acts as the reference map for validation.

2. unordered_map<string, int> tempFreq:
   - Tracks the frequency of words in the current sliding window.
   - Dynamically updated as the window expands or shrinks.

3. vector<int> ans:
   - Stores all starting indices where a valid concatenation is found.

4. string:
   - Used for substring extraction (`substr`) to isolate words of fixed length.

*/

/*
Optimizations Used to solve this question:

1. Sliding Window Optimization:
   - Reuses previously processed data instead of rebuilding frequency maps for each index.
   - Ensures each word is processed at most twice (once added, once removed).

2. Offset-Based Traversal:
   - The algorithm iterates over `wordLen` different starting offsets.
   - This guarantees correct word alignment and avoids invalid substring checks.

3. Avoiding Full Map Comparisons:
   - Instead of comparing two maps at every index, the algorithm maintains a word count.
   - This eliminates expensive hash map equality checks.

4. Early Reset on Invalid Words:
   - If a word is not in `freq`, the window is cleared immediately.
   - Prevents unnecessary computations for impossible substrings.

5. Linear Time Complexity:
   - The combined use of sliding window and hashing ensures O(n) time complexity.
   - This optimization is essential to pass worst-case inputs with repeated characters.

*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        if (words.empty()) return {};

        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();

        if (s.size() < totalLen) return {};

        unordered_map<string, int> freq;
        for (auto &w : words) {
            freq[w]++;
        }

        vector<int> ans;

        for (int i = 0; i < wordLen; i++) {

            unordered_map<string, int> tempFreq;
            int left = i;
            int count = 0;

            for (int j = i; j + wordLen <= s.size(); j += wordLen) {

                string curr = s.substr(j, wordLen);

                if (freq.count(curr)) {
                    tempFreq[curr]++;
                    count++;

                    while (tempFreq[curr] > freq[curr]) {
                        string leftWord = s.substr(left, wordLen);
                        tempFreq[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    if (count == words.size()) {
                        ans.push_back(left);
                    }
                }else {
                    tempFreq.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return ans;
    }
};