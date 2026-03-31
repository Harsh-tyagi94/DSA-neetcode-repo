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
    int smallkth(TreeNode* root,int &k,int &ans){
        if(root==nullptr || k==0){
            return ans;
        }
        int left=smallkth(root->left,k,ans);
        if(k==1){
            k--;
            ans=root->val;
            return ans;
        }
        k--;
        int right=smallkth(root->right,k,ans);
        return max(left,right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr || k==0){
            return 0;
        }
        int ans=0,cnt=k;
        return smallkth(root,cnt,ans);
    }
};
