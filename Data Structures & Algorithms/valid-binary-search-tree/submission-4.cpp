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
    bool is_validate_bst(TreeNode* root, long long l, long long r) {
        if(!root) return true;

        if(l >= root->val || r <= root->val) return false;
        bool left = is_validate_bst(root->left, l, root->val);
        bool right = is_validate_bst(root->right, root->val, r);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return is_validate_bst(root, -1e18, 1e18);
    }
};