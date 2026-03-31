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
    int prevIdx = 0;
    unordered_map<int,int> ump;
    TreeNode* build(vector<int>& preorder,int l,int r) {
        if(l>r) return nullptr;
        int v = preorder[prevIdx++];
        TreeNode* root = new TreeNode(v);
        int mid = ump[v];
        root->left = build(preorder,l,mid-1);
        root->right = build(preorder,mid+1,r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        for(int i=0;i<n;i++) ump[inorder[i]] = i;

        return build(preorder,0,n-1);
    }
};
