/*
Concepts Used to solve this question:

1. Digit Place Analysis:
   - The algorithm analyzes the number digit by digit (ones, tens, hundreds, etc.).
   - Each digit position is processed independently to count how many times digit '1'
     appears at that position across all numbers from 1 to n.

2. Mathematical Decomposition:
   - For a given digit position (`factor`), the number is split into three parts:
     - higher: digits to the left of the current position
     - curr: the digit at the current position
     - lower: digits to the right of the current position
   - This decomposition allows precise counting without iterating through all numbers.

3. Case-Based Counting:
   - The count contribution depends on the value of the current digit:
     - If curr == 0 → contribution depends only on higher digits
     - If curr == 1 → contribution includes higher digits plus lower + 1
     - If curr > 1 → contribution includes (higher + 1)

4. Iterative Place Value Traversal:
   - A factor variable (1, 10, 100, ...) is used to move across digit places.
   - The loop continues until all digit positions of n are processed.

5. Avoiding Brute Force:
   - Instead of checking every number from 1 to n, the algorithm uses
     mathematical patterns to achieve efficiency.

*/

/*
Data Structures Used to solve this question:

1. long long factor:
   - Represents the current digit place being evaluated (ones, tens, etc.).
   - Uses long long to safely handle large values.

2. int count:
   - Accumulates the total number of occurrences of digit '1'.

3. long long lower, curr, higher:
   - Temporary variables used to store decomposed parts of the number n
     relative to the current digit position.

*/

/*
Optimizations Used to solve this question:

1. Constant Space Usage:
   - No extra data structures are used; only a few variables are maintained.
   - Space complexity remains O(1).

2. Logarithmic Time Complexity:
   - The algorithm processes each digit position once.
   - Time complexity is O(log10(n)), which is significantly faster than O(n).

3. Mathematical Counting:
   - Leverages digit frequency patterns instead of enumerating all numbers.
   - Eliminates unnecessary iterations and comparisons.

4. Overflow Safety:
   - Uses long long for factor and digit calculations to avoid integer overflow
     when handling large values of n.

*/

class Solution {
public:
    int countDigitOne(int n) {
        long long factor = 1;
        int count = 0;

        while (factor <= n) {
            long long lower = n % factor;
            long long curr  = (n / factor) % 10;
            long long higher = n / (factor * 10);

            if (curr == 0)
                count += higher * factor;
            else if (curr == 1)
                count += higher * factor + lower + 1;
            else
                count += (higher + 1) * factor;

            factor *= 10;
        }
        return count;
    }
};
