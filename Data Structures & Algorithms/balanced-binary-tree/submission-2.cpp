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
    bool res = true;
    int isheightBalanced(TreeNode* root) {
        if(!res || !root) return 0;

        int l = (!res) ? 0 : isheightBalanced(root->left);
        int r = (!res) ? 0 : isheightBalanced(root->right);

        if(abs(l-r) > 1) res = false;

        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int h = isheightBalanced(root);
        return res;
    }
};