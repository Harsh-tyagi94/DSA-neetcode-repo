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
    int PathSum(TreeNode* root, int& res) {
        if(!root) return 0;

        int l = max(0, PathSum(root->left, res));
        int r = max(0, PathSum(root->right, res));

        res = max(res, root->val + l + r);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int res = root->val;
        int d = PathSum(root, res);
        return res;
    }
};