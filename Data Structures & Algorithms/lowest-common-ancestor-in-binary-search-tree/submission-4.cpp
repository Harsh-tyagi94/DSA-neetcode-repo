/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root->val >= p->val && root->val <= q->val) return root;
        else if(root->val > p->val && root->val > q->val) return lca(root->left, p, q);
        else return lca(root->right, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(p->val > q->val) {
            TreeNode* t = p;
            p = q;
            q = t;
        }
        return lca(root, p, q);
    }
};