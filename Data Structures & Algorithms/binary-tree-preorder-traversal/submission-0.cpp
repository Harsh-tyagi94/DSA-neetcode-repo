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
class Solution {
public:
    TreeNode* precedance(TreeNode* root) {
        if(!root) return nullptr;

        TreeNode* curr = root->left;
        while(curr->right && curr->right != root) curr = curr->right;

        return curr;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        while(root) {
            if(!root->left) {
                res.push_back(root->val);
                root = root->right;
            } else {
                TreeNode* curr = precedance(root);

                if(curr->right == nullptr) {
                    res.push_back(root->val);
                    curr->right = root;
                    root = root->left;
                } else {
                    curr->right = nullptr;
                    root = root->right;
                }
            }
        }
        return res;
    }
};