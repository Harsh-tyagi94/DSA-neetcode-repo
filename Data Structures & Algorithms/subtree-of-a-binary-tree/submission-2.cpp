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
    bool SubTree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return subRoot == nullptr ? true : false;
        if(!subRoot || root->val != subRoot->val) return false;

        return SubTree(root->left, subRoot->left) && SubTree(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;

        queue<TreeNode*> Queue;
        Queue.push(root);
        while(!Queue.empty()) {
            int len = Queue.size();
            for(int i=0;i<len;i++) {
                TreeNode* curr = Queue.front(); Queue.pop();
                if(curr->val == subRoot->val && SubTree(curr, subRoot)) return true;

                if(curr->left) Queue.push(curr->left);
                if(curr->right) Queue.push(curr->right);
            }
        }
        return false;
    }
};