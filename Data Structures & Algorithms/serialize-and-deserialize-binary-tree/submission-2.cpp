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
        queue<TreeNode*> q;
        q.push(root);

        string tokenize = "";
        while(!q.empty()) {
            int len = q.size();
            for(int i=0;i<len;i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr == nullptr) tokenize += '#';
                else {
                    tokenize += to_string(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
                tokenize += '.';
            }
        }
        return tokenize;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        string token = "";
        getline(ss, token, '.');
        if(token == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while(getline(ss, token, '.')) {
            TreeNode* curr = q.front();
            q.pop();

            if(token != "#") {
                curr->left = new TreeNode(stoi(token));
                q.push(curr->left);
            }

            getline(ss, token, '.');
            if(token != "#") {
                curr->right = new TreeNode(stoi(token));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));