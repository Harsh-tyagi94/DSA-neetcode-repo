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
    unordered_map<int, int> ump;
    int index = 0;
    TreeNode* actual_treebuild(vector<int>& preorder, int l, int r) {
        if(l > r) return nullptr;
        int val = preorder[index++];
        TreeNode* root = new TreeNode(val);
        root->left = actual_treebuild(preorder, l, ump[val]-1);
        root->right = actual_treebuild(preorder, ump[val]+1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i=0;i<n;i++) {
            ump[inorder[i]] = i;
        }
        return actual_treebuild(preorder, 0, n-1);
    }
};