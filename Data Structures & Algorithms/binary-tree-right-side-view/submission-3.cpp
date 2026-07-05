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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> Queue;
        Queue.push(root);
        vector<int> res;
        while(!Queue.empty()) {
            int len = Queue.size();
            for(int i=0;i<len;i++) {
                TreeNode* curr = Queue.front();
                Queue.pop();

                if(i == len - 1) res.push_back(curr->val);

                if(curr->left) Queue.push(curr->left);
                if(curr->right) Queue.push(curr->right); 
            }
        }
        return res;
    }
};