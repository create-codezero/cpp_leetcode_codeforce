/*
Concepts Used to solve this question:

1. Brute Force with Optimization:
   - Each point is treated as an anchor point.
   - Slopes with all other points are calculated relative to the anchor.

2. Slope-Based Line Identification:
   - Points lying on the same line share the same slope.
   - Slopes are used as keys to group collinear points.

3. Hashing for Frequency Counting:
   - A hash map stores how many points share the same slope
     with the current anchor point.

4. Vertical Line Handling:
   - Vertical lines have an undefined slope.
   - These are counted separately using a dedicated counter.

5. Maximum Tracking:
   - For each anchor, the maximum number of collinear points
     is computed and compared with the global maximum.

*/

/*
Data Structures Used to solve this question:

1. unordered_map<float, int> tempTable:
   - Stores slope frequencies for the current anchor point.

2. int tempAndhi:
   - Counts the number of points forming a vertical line
     with the current anchor.

3. int ans:
   - Stores the maximum number of points lying on the same line.

4. vector<vector<int>>& points:
   - Input list of 2D points.

*/

/*
Optimizations Used to solve this question:

1. Reduced Redundant Comparisons:
   - Each point is compared only with points after it,
     avoiding duplicate slope calculations.

2. On-the-fly Maximum Update:
   - The maximum collinear points for each anchor
     are computed immediately.

3. Separate Vertical Line Count:
   - Avoids division by zero and simplifies slope handling.

4. Early Edge Case Handling:
   - Handles cases with 0 or 1 point efficiently.

*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        if (points.size() == 1) {
            return 1;
        } else if (points.size() == 0) {
            return 0;
        }

        int ans = INT_MIN;

        for (int i = 0; i < points.size() - 1; i++) {
            unordered_map<float, int> tempTable;
            int tempAndhi = 0;

            for (int j = i + 1; j < points.size(); j++) {
                float numr = points[j][1] - points[i][1];
                float demr = points[j][0] - points[i][0];

                if (demr == 0) {
                    tempAndhi++;
                } else {
                    float m = numr / demr;
                    tempTable[m]++;
                }
            }

            for (auto e : tempTable) {
                if (tempAndhi < e.second) {
                    tempAndhi = e.second;
                }
            }

            if (ans < tempAndhi) {
                ans = tempAndhi;
            }
        }

        return ans + 1;
    }
};
