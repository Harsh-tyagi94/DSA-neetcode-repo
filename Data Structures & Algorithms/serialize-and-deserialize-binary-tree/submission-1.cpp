/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();
            for(int i=0;i<len;i++) {
                auto curr = q.front();
                q.pop();

                if(!curr) res += "#,";
                else {
                    res += to_string(curr->val)+',';
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == '#') return nullptr;

        stringstream ss(data);
        string token;
        getline(ss,token,',');
        TreeNode* root = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            if(getline(ss,token,',')) {
                if(token != "#") {
                    curr->left = new TreeNode(stoi(token));
                    q.push(curr->left);
                }
            }
            if(getline(ss,token,',')) {
                if(token != "#") {
                    curr->right = new TreeNode(stoi(token));
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};
