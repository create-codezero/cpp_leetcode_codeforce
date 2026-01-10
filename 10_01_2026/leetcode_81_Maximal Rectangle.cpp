/*
CONCEPTS USED:
Histogram	✅
Monotonic Stack	✅
Dynamic Programming	✅
Greedy Strategy	✅
Stack Data Structure	✅
Array / Vector	✅

One-line Insight : Convert each row into a histogram and solve Largest Rectangle in Histogram using a monotonic stack.

--------------------------------------------------------------
DATA STRUCTURES USED:
1. Vector
2. Stack

--------------------------------------------------------------

SOLUTION STRATEGY:
🔑 One Core Idea (Most Important)
Har row ko histogram samjho
Aur har histogram ke liye Largest Rectangle in Histogram ka problem solve karo.

Step 1: Histogram Banane ka Concept
    Socho matrix ko row by row traverse kar rahe ho.
    Har column ke liye ek height array maintain karo:

    Agar current cell '1' hai → height +1
    Agar '0' hai → height = 0

    matrix:
    1 0 1 1 1
    1 1 1 1 1
    0 1 1 1 1

    heights after each row:
    [1, 0, 1, 1, 1] -> r1
    [2, 1, 2, 2, 2] -> r2
    [0, 2, 3, 3, 3] -> r3

Step 2: Why Histogram Problem?
    Har histogram me tum:
    Bars ki heights jaante ho
    Bars consecutive hain
    Tumhe maximum area rectangle chahiye
    Ye exactly Largest Rectangle in Histogram problem hai.

Step 3: Largest Rectangle in Histogram (Concept Only)
    Histogram ke liye:
        Ek monotonic increasing stack use hota hai
        Stack indices store karta hai
        Jab current height chhoti ho jaati hai:
        Stack ke top ko pop karo

    Area calculate karo:
        height[top] × width

    Width ka idea:
        Right boundary → current index
        Left boundary → stack ka new top

Step 4: Monotonic Stack Ka Role
    Stack ka invariant:
        heights[stack[0]] <= heights[stack[1]] <= ...

    Matlab:
        Stack hamesha increasing order me heights rakhta hai
        Jaise hi smaller height aayi → rectangle close ho jata hai

Step 5: Greedy + DP Angle
    Greedy:
    Har bar maximum possible rectangle banane ki koshish
    Jab height kam hoti hai, turant area calculate karte hain

    DP:
    Histogram heights accumulate ho rahe hain row by row
    Previous row ka result reuse hota hai

Step 6: Final Algorithm Flow
    Ek heights array banao (size = columns)
    Har row ke liye:
        Update heights
        Histogram ke max rectangle ka area nikalo
        Global max update karo
        Final answer return karo

Step 7: Time & Space Complexity
    Time Complexity:
        Har row → O(cols)
        Har histogram solve → O(cols)
        Total → O(rows × cols)

    Space Complexity:
        Heights array → O(cols)
        Stack → O(cols)


Final One-Line Explanation (Interview Ready)
    “We treat each row of the matrix as the base of a histogram, update heights dynamically, and apply the Largest Rectangle in Histogram algorithm using a monotonic stack to compute the maximal rectangle efficiently.”


Visual Example (Row 2: [2, 1, 2, 2, 2])
    k = 0 → stack = [0]
    k = 1 → h=1 < height[0]=2 → pop 0, width=1, area=2 → maxArea=2, stack=[1]
    k = 2 → h=2 ≥ stack top height=1 → push 2 → stack=[1,2]
    k = 3 → h=2 ≥ stack top height=2 → push 3 → stack=[1,2,3]
    k = 4 → h=2 ≥ stack top height=2 → push 4 → stack=[1,2,3,4]
    k = 5 → dummy h=0 < height[4]=2 → pop 4, width=1, area=2
    pop 3, width=2, area=4
    pop 2, width=3, area=6 → maxArea=6
    pop 1, width=5, area=5 → maxArea still 6

    ✅ Max rectangle = 6


*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        vector<int> height(matrix[0].size(), 0);
        int maxArea = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < height.size(); j++){
                if(matrix[i][j] == '0'){
                    height[j] = 0;
                } else {
                    height[j] += 1;
                }
            }

            stack<int> st;
            int n = height.size();

            for(int k = 0; k <= n; k++){
                int h = (k == n ? 0 : height[k]);

                while(!st.empty() && h < height[st.top()]){
                    int topIndex = st.top(); st.pop();
                    int width = st.empty() ? k : k - st.top() - 1;
                    int area = height[topIndex] * width;
                    maxArea = max(maxArea, area);
                }
                st.push(k);
            }

        }

        return maxArea;
    }
};
