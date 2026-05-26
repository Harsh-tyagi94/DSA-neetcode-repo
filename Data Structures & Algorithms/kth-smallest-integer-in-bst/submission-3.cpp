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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<int> qmax;
        q.push(root);

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            if(qmax.size() < k) {
                qmax.push(curr->val);
            } else {
                if(qmax.top() > curr->val) {
                    qmax.pop();
                    qmax.push(curr->val);
                }
            }

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return qmax.top();
    }
};