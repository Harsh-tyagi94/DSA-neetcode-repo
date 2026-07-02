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
    void preorder_traversal(TreeNode* root, vector<int>& preorder) {
        if(!root) return;
        preorder.push_back(root->val);
        preorder_traversal(root->left, preorder);
        preorder_traversal(root->right, preorder);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        preorder_traversal(root, preorder);
        return preorder;
    }
};