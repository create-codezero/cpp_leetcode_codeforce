/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode*> q;

        // pre-order level wise traversal
        q.push(root);
        s += to_string(root->val);


        while(!q.empty()){
            TreeNode* node = q.front();

            if(node->left == NULL){
                s += ",#";
            }else{
                q.push(node->left);
                s += "," + to_string(node->left->val);
            }

            if(node->right == NULL){
                s += ",#";
            }else{
                q.push(node->right);
                s += "," + to_string(node->right->val);
            }

            q.pop();
        }

        cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        vector<string> s;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            s.push_back(token);
        }

        

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(s[0]));
        q.push(root);
        int sFront = 0;
        while(!q.empty() && sFront < s.size()){
            TreeNode* curr = q.front();
            string left;
            string right;

            if(sFront+1 < s.size()){
                left = s[++sFront];
            }else{
                left = "#";
            }

            if(sFront+1 < s.size()){
                right = s[++sFront];
            }else{
                right = "#";
            }

            if(left == "#"){
                
            }else{
                TreeNode* leftNode = new TreeNode(stoi(left));
                curr->left = leftNode;
                q.push(leftNode);
            }
            
            if(right == "#"){
                curr->right = NULL;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(right));
                curr->right = rightNode;
                q.push(rightNode);
            }

            q.pop();
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));