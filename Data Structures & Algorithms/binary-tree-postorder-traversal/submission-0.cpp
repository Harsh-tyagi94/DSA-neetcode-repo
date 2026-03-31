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
    TreeNode* succedance(TreeNode* root) {
        if(!root) return root;

        TreeNode* curr = root->right;
        while(curr->left && curr->left != root) curr = curr->left;

        return curr;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;

        while(root) {
            if(!root->right) {
                res.push_back(root->val);
                root = root->left;
            } else {
                TreeNode* curr = succedance(root);

                if(!curr->left) {
                    res.push_back(root->val);
                    curr->left = root;
                    root = root->right;
                } else {
                    curr->left = nullptr;
                    root = root->left;
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};