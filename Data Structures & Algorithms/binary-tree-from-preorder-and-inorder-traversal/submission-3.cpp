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
    int index = 0;
    TreeNode* actualbuildtree(vector<int>& preorder, unordered_map<int, int>& ump, int l, int r) {
        if(l > r) return nullptr;

        int value = preorder[index++];
        TreeNode* root = new TreeNode(value);

        root->left = actualbuildtree(preorder, ump, l, ump[value] - 1);
        root->right = actualbuildtree(preorder, ump, ump[value] + 1, r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if(n == 0) return nullptr;
        unordered_map<int, int> ump;
        for(int i=0;i<n;i++) ump[inorder[i]] = i;
        return actualbuildtree(preorder, ump, 0, n-1);
    }
};