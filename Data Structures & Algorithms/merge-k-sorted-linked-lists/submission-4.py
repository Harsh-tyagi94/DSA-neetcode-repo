# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        qmin = []

        for i, node in enumerate(lists):
            if node:
                heapq.heappush(qmin, (node.val, i, node)) # i is there just for tie breaker as diff. bt c++ & py.
        
        res = ListNode()
        curr = res
        while qmin:
            val, i, node = heapq.heappop(qmin)

            curr.next = ListNode(val)
            curr = curr.next

            if node.next:
                heapq.heappush(qmin, (node.next.val, i, node.next))
        
        return res.next