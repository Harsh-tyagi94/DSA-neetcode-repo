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
    bool ischeck = true;
    int isHeightBalanced(TreeNode* root) {
        if(!root) return 0;

        int l = isHeightBalanced(root->left);
        int r = isHeightBalanced(root->right);

        if(!ischeck) return -1;

        if(abs(l-r) > 1) {
            ischeck = false;
            return -1;
        }

        return 1 + max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) true;

        int ans = isHeightBalanced(root);
        return ischeck;
    }
};
