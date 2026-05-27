# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        arr = []

        def traversal(root) -> None:
            if not root:
                return
            
            traversal(root.left)
            arr.append(root.val)
            traversal(root.right)
            return
        
        traversal(root)
        return arr[k-1]