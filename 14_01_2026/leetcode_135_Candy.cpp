/*
Concepts Used to solve this question:

1. Greedy Distribution:
   - Each child must receive at least one candy.
   - Additional candies are given only when required by rating constraints.

2. Bidirectional Constraint Enforcement:
   - Left neighbor constraint:
       If ratings[i] > ratings[i - 1], then candies[i] > candies[i - 1].
   - Right neighbor constraint:
       If ratings[i] > ratings[i + 1], then candies[i] > candies[i + 1].

3. Two-Pass Technique:
   - First pass (Left to Right) ensures left-side constraints.
   - Second pass (Right to Left) ensures right-side constraints.

4. Dependency Ordering:
   - Candy assignment depends on previously computed neighbors.
   - Separate passes guarantee correct dependency resolution.

5. Minimization Strategy:
   - Candies are only increased when required.
   - The final result is the minimum valid distribution.

*/

/*
Data Structures Used to solve this question:

1. vector<int> ratings:
   - Input array representing ratings of children.

2. vector<int> candies:
   - Stores the number of candies assigned to each child.
   - Initialized with 1 candy for every child.

3. int totalSpended:
   - Accumulates the total number of candies distributed.

*/

/*
Optimizations Used to solve this question:

1. Linear Time Complexity:
   - Two linear passes over the ratings array.
   - Overall time complexity is O(n).

2. Efficient Space Usage:
   - Uses a single auxiliary array of size n.
   - Space complexity is O(n).

3. Avoidance of Redundant Computation:
   - No repeated scanning of neighbors.
   - Each dependency is resolved exactly once.

4. Safe Greedy Updates:
   - Uses max() in the second pass to preserve left-pass constraints.

*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalSpended = 0;
        for (int c : candies) {
            totalSpended += c;
        }

        return totalSpended;
    }
};
