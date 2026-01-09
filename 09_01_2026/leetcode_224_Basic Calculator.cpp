/*
Concepts Used to solve this question:

1. Infix to Postfix Conversion (Shunting Yard Algorithm):
   - Converts an infix expression into postfix notation.
   - Operator precedence and parentheses are handled using a stack.
   - Postfix notation allows straightforward evaluation.

2. Robust Unary Minus Handling:
   - Unary minus can appear:
     a) At the start of the expression
     b) After '('
     c) After another operator
     d) With arbitrary spaces (e.g., "1-(     -2)")
   - Unary minus is normalized by inserting a leading zero:
     "-2" → "0 2 -"
   - This guarantees binary operators during postfix evaluation.

3. Space-Insensitive Parsing:
   - Spaces are ignored during parsing.
   - Unary detection checks the previous *non-space* character.

4. Stack-Based Postfix Evaluation:
   - Numbers are pushed onto a stack.
   - Operators pop exactly two operands.
   - Safe evaluation prevents stack underflow and undefined behavior.

5. Integer Arithmetic:
   - Division truncates toward zero (C++ standard behavior).
   - Matches LeetCode constraints.

*/

/*
Data Structures Used to solve this question:

1. stack<char>:
   - Stores operators and parentheses during infix parsing.

2. vector<string>:
   - Stores postfix tokens (numbers and operators).

3. stack<long long>:
   - Evaluates the postfix expression safely.

4. string:
   - Used for parsing numbers and operators.

*/

/*
Optimizations Used to solve this question:

1. Linear Time Complexity:
   - Infix to postfix conversion: O(n)
   - Postfix evaluation: O(n)

2. Safe Unary Minus Normalization:
   - Prevents stack underflow and misaligned memory access.
   - Eliminates UndefinedBehaviorSanitizer errors.

3. No Recursion:
   - Entire solution uses iterative stack-based logic.

4. Minimal Extra Space:
   - Only postfix tokens and stacks are used.

*/

class Solution {
public:
    int prec(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    // Helper to find previous non-space character
    char prevNonSpace(const string &s, int i) {
        i--;
        while (i >= 0 && s[i] == ' ') i--;
        return (i >= 0 ? s[i] : '#');
    }

    vector<string> infixToPostfix(string s) {
        vector<string> output;
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == ' ') continue;

            // Parse full number
            if (isdigit(s[i])) {
                string num;
                while (i < s.size() && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                i--;
                output.push_back(num);
            }
            // Opening parenthesis
            else if (s[i] == '(') {
                st.push('(');
            }
            // Closing parenthesis
            else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    output.push_back(string(1, st.top()));
                    st.pop();
                }
                st.pop(); // remove '('
            }
            // Operator
            else {
                // Detect unary minus safely (with spaces)
                if (s[i] == '-') {
                    char prev = prevNonSpace(s, i);
                    if (prev == '#' || prev == '(' || prev == '+' || prev == '-' ||
                        prev == '*' || prev == '/') {
                        output.push_back("0");
                    }
                }

                while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                    output.push_back(string(1, st.top()));
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            output.push_back(string(1, st.top()));
            st.pop();
        }

        return output;
    }

    int calculate(string s) {
        // Convert infix to postfix
        vector<string> postfix = infixToPostfix(s);

        // Evaluate postfix expression
        stack<long long> st;

        for (auto &token : postfix) {

            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            } else {
                st.push(stoll(token));
            }
        }

        return st.top();
    }
};
