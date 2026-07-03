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
    pair<int, bool> isheightbalanced(TreeNode* root) {
        if(!root) return {0, true};

        pair<int, bool> l = isheightbalanced(root->left);
        pair<int, bool> r = isheightbalanced(root->right);
        if(!l.second || !r.second) return {-1, (l.second && r.second)};
        if(abs(l.first - r.first) > 1) return {-1, false};

        return {1 + max(l.first, r.first), true};
    }
    bool isBalanced(TreeNode* root) {
        pair<int, bool> res = isheightbalanced(root);
        return res.second;
    }
};