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
    int count_good_nodes(TreeNode* root, int value) {
        if(!root) return 0;

        int res = 0;
        if(root->val >= value) res += 1;
        res += count_good_nodes(root->left, max(root->val, value));
        res += count_good_nodes(root->right, max(root->val, value));
        return res;
    }
    int goodNodes(TreeNode* root) {
        return count_good_nodes(root, root->val);
    }
};