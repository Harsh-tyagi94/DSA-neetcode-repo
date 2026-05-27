# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        
        def is_validate_BST(root: Optional[TreeNode], l, r) -> bool:
            if not root:
                return True
            
            if l >= root.val or r <= root.val:
                return False
            
            left = is_validate_BST(root.left, l, root.val)
            right = is_validate_BST(root.right, root.val, r)

            return left and right

        return is_validate_BST(root, -1e18, 1e18)