# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        def find_count(root: TreeNode, value: int) -> int:
            if not root:
                return 0
            
            res = 0
            if root.val >= value:
                res += 1
            
            res += find_count(root.left, max(value, root.val))
            res += find_count(root.right, max(value, root.val))
            return res

        return find_count(root, root.val);