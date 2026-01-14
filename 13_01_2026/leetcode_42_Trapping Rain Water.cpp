/*
Concepts Used to solve this question:

1. Boundary-Based Water Trapping:
   - Water trapped at any index depends on the maximum height to its left
     and the maximum height to its right.
   - The effective water level is determined by the smaller of these two boundaries.

2. Two Pointer Technique:
   - Two pointers are used: one starting from the left and one from the right.
   - This allows processing the array from both ends simultaneously.

3. Greedy Decision Making:
   - At each step, the pointer with the smaller height is processed.
   - This is safe because water trapping is limited by the smaller boundary.

4. Dynamic Maximum Tracking:
   - As pointers move inward, the maximum height encountered so far from each side
     is maintained.
   - These maxima are used to compute trapped water efficiently.

5. Incremental Water Calculation:
   - Water is calculated on the fly while traversing the array.
   - This avoids recomputation and redundant scans.

*/

/*
Data Structures Used to solve this question:

1. vector<int>& height:
   - Input array representing bar heights.

2. int left, right:
   - Two pointers used to traverse the array from both ends.

3. int leftMax, rightMax:
   - Track the maximum bar height encountered so far from the left and right sides.

4. int ans:
   - Accumulates the total amount of trapped rain water.

*/

/*
Optimizations Used to solve this question:

1. Linear Time Complexity:
   - Each index is processed exactly once.
   - Time complexity is O(n), where n is the number of bars.

2. Constant Space Usage:
   - No auxiliary arrays or stacks are used.
   - Space complexity remains O(1).

3. Avoiding Repeated Computation:
   - Unlike brute-force solutions, maximum heights are not recalculated for each index.
   - This significantly improves performance.

4. Safe Greedy Strategy:
   - Always processing the side with the smaller height guarantees correctness
     without needing full left and right scans.

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = height.size() - 1;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    ans += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};
