/*
Concepts Used to solve this question:

1. Breadth-First Search (BFS):
   - Each board configuration is treated as a node in a graph.
   - BFS is used to find the minimum number of moves required to reach the target configuration.

2. State Representation Using Strings:
   - The 2x3 board is flattened into a string for easy comparison and storage.
   - This allows efficient hashing and equality checks.

3. Graph Transitions via Predefined Moves:
   - For each position of '0' (empty tile), predefined valid swap positions are used
     to generate neighboring states.

4. Level-by-Level Traversal:
   - BFS is performed level by level to accurately count the number of moves (steps).

*/

/*
Data Structures Used to solve this question:

1. string start, target:
   - Represent the initial and target board configurations.

2. vector<vector<int>> moves:
   - Stores all valid index swaps for each position of '0'.

3. queue<string> q:
   - Used for BFS traversal of board states.

4. unordered_set<string> vis:
   - Keeps track of visited states to avoid revisiting and infinite loops.

5. int steps:
   - Counts the number of moves taken to reach the target state.

*/

/*
Optimizations Used to solve this question:

1. Efficient State Encoding:
   - Using a string to represent the board reduces memory overhead
     and allows O(1) average lookup in the visited set.

2. Precomputed Valid Moves:
   - Eliminates the need to calculate neighbors dynamically for each state.

3. Early Termination:
   - BFS stops immediately once the target configuration is found,
     ensuring minimum steps are returned.

*/

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start, target = "123450";
        for (auto& r : board)
            for (int x : r)
                start.push_back(char('0' + x));

        vector<vector<int>> moves = {
            {1,3}, {0,2,4}, {1,5},
            {0,4}, {1,3,5}, {2,4}
        };

        queue<string> q;
        unordered_set<string> vis;
        q.push(start);
        vis.insert(start);

        int steps = 0;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string cur = q.front();
                q.pop();

                if (cur == target) return steps;

                int z = cur.find('0');
                for (int m : moves[z]) {
                    string nxt = cur;
                    swap(nxt[z], nxt[m]);
                    if (!vis.count(nxt)) {
                        vis.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
