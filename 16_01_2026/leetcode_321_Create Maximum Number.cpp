/*
Concepts Used to solve this question:

1. Greedy Stack Approach for Maximum Subarray:
   - To get the largest number of length `n` from a given array while maintaining order.
   - Use a stack to keep track of the digits, popping smaller ones if a larger one comes
     and we still have "drops" available.

2. Merging Two Arrays Lexicographically:
   - Merge two arrays into the largest possible number while maintaining relative order.
   - In case of a tie, compare the remaining subarrays to decide which element to pick.

3. Iterating Over All Splits:
   - The final number of length `k` can be split between nums1 and nums2 in multiple ways.
   - We iterate over all valid splits and select the maximum lexicographical result.

4. Lexicographical Comparison:
   - Compare arrays element by element to decide which merged result is larger.

*/

/*
Data Structures Used to solve this question:

1. vector<int> stack:
   - Used in `createMaxArray` to greedily construct the maximum number of a certain length.

2. vector<int> finalMerged:
   - Stores the merged result of two arrays while maintaining lexicographical maximum.

3. int drop:
   - Tracks how many elements can be removed to achieve the required size in `createMaxArray`.

4. int i, j:
   - Pointers used to merge two arrays.

5. vector<int> ans:
   - Stores the currently known largest number across all splits.

*/

/*
Optimizations Used to solve this question:

1. Linear Time Stack Construction:
   - Each element is pushed and popped at most once.
   - Ensures createMaxArray runs in O(n) time.

2. Efficient Merge Using Lexicographical Comparison:
   - Avoids repeated string/array comparisons by only looking at remaining subarrays when elements are equal.

3. Iterating Over Valid Splits Only:
   - Only iterate over splits where lengths sum to k.
   - Avoids unnecessary computation.

*/

class Solution {
public:
    vector<int> createMaxArray(vector<int>& arr, int n) {
        vector<int> stack;
        int drop = arr.size() - n;  // number of elements we can remove

        for (int val : arr) {
            while (!stack.empty() && drop > 0 && stack.back() < val) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(val);
        }

        stack.resize(n);  // keep only n elements
        return stack;
    }

    void merge(vector<int>& temp1, vector<int>& temp2, vector<int>& t) {
        int i = 0, j = 0;
        vector<int> finalMerged;

        while (i < temp1.size() || j < temp2.size()) {
            if (i == temp1.size()) {
                while (j < temp2.size()) {
                    finalMerged.push_back(temp2[j]);
                    j++;
                }
            } else if (j == temp2.size()) {
                while (i < temp1.size()) {
                    finalMerged.push_back(temp1[i]);
                    i++;
                }
            } else {
                if (temp1[i] > temp2[j]) {
                    finalMerged.push_back(temp1[i]);
                    i++;
                } else if (temp1[i] < temp2[j]) {
                    finalMerged.push_back(temp2[j]);
                    j++;
                } else {
                    // tie: compare remaining subarrays lexicographically
                    int ii = i, jj = j;
                    while (ii < temp1.size() && jj < temp2.size() && temp1[ii] == temp2[jj]) {
                        ii++;
                        jj++;
                    }

                    if (jj == temp2.size() || (ii < temp1.size() && temp1[ii] > temp2[jj])) {
                        finalMerged.push_back(temp1[i]);
                        i++;
                    } else {
                        finalMerged.push_back(temp2[j]);
                        j++;
                    }
                }
            }
        }

        t = finalMerged;
    }

    void printVector(vector<int>& a) {
        // for (auto val : a) {
        //     cout << val << ", ";
        // }
        // cout << endl;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int y = min((int)nums2.size(), k);
        int x = k - y;
        vector<int> ans;

        while (x <= nums1.size() && y >= 0) {
            // cout << endl << "Current x and y values : " << x << ", " << y << endl;
            vector<int> temp1 = createMaxArray(nums1, x);
            vector<int> temp2 = createMaxArray(nums2, y);

            // cout << "temp1 : " << endl;
            printVector(temp1);
            // cout << "temp2 : " << endl;
            printVector(temp2);

            vector<int> mergedTemp;
            merge(temp1, temp2, mergedTemp);

            // cout << "mergedTemp : " << endl;
            printVector(mergedTemp);

            if (ans.empty()) {
                ans = mergedTemp;
            } else {
                int i = 0;
                int decided = 0;
                while (!decided && i < mergedTemp.size()) {
                    if (mergedTemp[i] != ans[i]) {
                        // cout << "New Decided!" << endl;
                        decided = 1;
                        if (mergedTemp[i] > ans[i]) {
                            ans = mergedTemp;
                        }
                    }
                    i++;
                }
            }

            x++;
            y--;
        }

        return ans;
    }
};
