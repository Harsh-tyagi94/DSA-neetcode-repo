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
    int res = INT_MIN;
    int maxSum(TreeNode* root) {
        if(!root) return 0;

        int l=0,r=0;

        if(root->left) {
            l = maxSum(root->left);
            if(res < l) res = l;
        }
        

        if(root->right) {
            r = maxSum(root->right);
            if(res < r) res = r;
        }
        

        int ans = root->val + max(l,r);


        res = max({res,root->val,l+r+root->val,ans});

        return max(root->val,ans);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int Sum=maxSum(root);
        return res;
    }
};
