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
    bool validateBST(TreeNode* root,long minval,long maxval) {
        if(!root) return true;

        if(!(root->val > minval && root->val < maxval)) return false;

        return validateBST(root->left,minval,root->val) 
                && validateBST(root->right,root->val,maxval);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        return validateBST(root,LONG_MIN,LONG_MAX);
    }
};
