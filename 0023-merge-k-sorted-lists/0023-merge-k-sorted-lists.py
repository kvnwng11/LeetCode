# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        dummy = ListNode(None)
        curr = dummy
        heap = []
        
        
        for i, l in enumerate(lists):
            if l:
                heapq.heappush(heap, (l.val, i, l))
                
        while len(heap) > 0:
            val, i, node = heapq.heappop(heap)
            curr.next = node
            curr = curr.next
            
            if node.next:
                heapq.heappush(heap, (node.next.val, i, node.next))
            
        
        return dummy.next