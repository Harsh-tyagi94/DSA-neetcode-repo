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
    unordered_map<int, int> ump;
    TreeNode* helper(vector<int>& preorder, int l, int r) {
        if(l>r) return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = helper(preorder, l, ump[root->val]-1);
        root->right = helper(preorder, ump[root->val]+1, r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i=0;i<n;i++) {
            ump[inorder[i]] = i;
        }
        return helper(preorder, 0, preorder.size()-1);
    }
};

/*
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]


root = nullptr
root = new nodo(pre[0]);
*/