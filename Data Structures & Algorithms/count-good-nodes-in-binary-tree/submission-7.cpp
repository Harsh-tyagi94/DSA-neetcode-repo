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
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int res = 1;
        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            if(curr->left) {
                int value = curr->left->val;
                if(curr->val <= value) res += 1;
                curr->left->val = max(value, curr->val);
                q.push(curr->left);
            }
            if(curr->right) {
                int value = curr->right->val;
                if(curr->val <= value) res += 1;
                curr->right->val = max(value, curr->val);
                q.push(curr->right);
            }
        }
        return res;
    }
};
