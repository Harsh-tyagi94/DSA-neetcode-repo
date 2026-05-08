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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> Queue;
        Queue.push(root);
        while(!Queue.empty()) {
            int len = Queue.size();
            vector<int> level_elements;
            for(int i=0;i<len;i++) {
                TreeNode* curr = Queue.front();
                Queue.pop();

                level_elements.push_back(curr->val);
                if(curr->left) Queue.push(curr->left);
                if(curr->right) Queue.push(curr->right);
            }
            res.push_back(level_elements);
        }
        return res;
    }
};