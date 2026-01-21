/*
Concepts Used to solve this question:

1. Depth-First Search (DFS):
   - The binary tree is traversed using DFS to compute path sums.
   - Each node is processed after its left and right subtrees.

2. Dynamic Programming on Trees:
   - At each node, we compute the maximum gain that can be extended to its parent.
   - Subproblems (left and right subtree gains) are reused efficiently.

3. Global Maximum Tracking:
   - A reference variable is used to track the maximum path sum found anywhere in the tree.
   - This allows paths that do not necessarily pass through the root.

4. Handling Negative Values:
   - Negative path contributions are ignored using max(0, ...),
     ensuring they do not reduce the overall path sum.

*/

/*
Data Structures Used to solve this question:

1. TreeNode (Binary Tree):
   - Represents nodes of the binary tree with left and right pointers.

2. int ans:
   - Stores the global maximum path sum encountered during traversal.
   - Passed by reference to update values across recursive calls.

*/

/*
Optimizations Used to solve this question:

1. Single DFS Traversal:
   - Each node is visited exactly once, resulting in O(n) time complexity.

2. Ignoring Negative Subtrees:
   - Using max(0, subtreeSum) avoids unnecessary path extensions.

3. No Extra Space for Storage:
   - No arrays, vectors, or hash maps are used.
   - Space complexity is O(h), where h is the height of the tree (recursion stack).

*/

class Solution {
public:
    int traverse(TreeNode* r, int &ans) {
        if (!r) return 0;

        int left = max(0, traverse(r->left, ans));
        int right = max(0, traverse(r->right, ans));

        // Update the maximum path sum considering a split at current node
        ans = max(ans, left + right + r->val);

        // Return the maximum gain that can be extended to the parent
        return r->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        traverse(root, ans);
        return ans;
    }
};
