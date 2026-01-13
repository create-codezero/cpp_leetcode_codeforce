/*
Concepts Used to solve this question:

1. Sliding Window Technique:
   - A fixed-size window of length `k` slides over the array `nums`.
   - At each step, the maximum element within the current window is recorded.

2. Monotonic Deque:
   - A deque is maintained such that elements are stored in decreasing order.
   - The front of the deque always contains the index of the maximum element
     for the current window.

3. Index-Based Window Management:
   - Indices are stored instead of values to efficiently check
     whether elements fall outside the current window range.

4. Greedy Removal Strategy:
   - While inserting a new element, all smaller elements at the back
     of the deque are removed since they cannot be maximum in future windows.

5. One-Pass Traversal:
   - The array is traversed only once, ensuring optimal performance.

*/

/*
Data Structures Used to solve this question:

1. deque<int> dq:
   - Stores indices of elements in decreasing order of their values.
   - Allows constant-time insertion and removal from both ends.

2. vector<int> ans:
   - Stores the maximum values for each sliding window.

*/

/*
Optimizations Used to solve this question:

1. Linear Time Complexity:
   - Each element is added and removed from the deque at most once.
   - Overall time complexity is O(n).

2. Constant Space per Window:
   - The deque holds at most k elements at any time.
   - Extra space complexity is O(k).

3. Avoiding Recomputations:
   - The maximum for each window is obtained in O(1) time from the deque front,
     instead of scanning the entire window.

4. Efficient Window Shrinking:
   - Elements that move out of the window are removed immediately,
     ensuring the deque remains valid.

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
