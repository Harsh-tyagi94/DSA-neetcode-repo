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
    TreeNode* delnode(TreeNode* root, int key) {
        if(root->val == key) {
            if(!root->right) return root->left;
            TreeNode* curr = root->right;
            while(curr && curr->left) {
                curr = curr->left;
            }
            curr->left = root->left;
            return root->right;
        } else if(root->val > key) {
            root->left = delnode(root->left, key);
        } else {
            root->right = delnode(root->right, key);
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        while(curr && curr->val != key) {
            if(curr->val > key) curr = curr->left;
            else curr = curr->right;
        }

        if(!curr) return root;

        // found now need to delete
        return delnode(root, key);        
    }
};