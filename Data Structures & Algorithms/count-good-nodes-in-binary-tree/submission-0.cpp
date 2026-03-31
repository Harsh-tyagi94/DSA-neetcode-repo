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
    void traverse(TreeNode* root,int value,int &cnt){
        if(root==nullptr)
        return ;
        if(value<=root->val){
            cnt++;
        }
        int v1=max(value,root->val);
        traverse(root->left,v1,cnt);
        traverse(root->right,v1,cnt);
    }   
    int goodNodes(TreeNode* root) {
        if(root==nullptr)
        return 0;
        int value=INT_MIN,cnt=0;
        traverse(root,value,cnt);
        return cnt;
    }
};
