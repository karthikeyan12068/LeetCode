# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head==None or head.next==None):
            return head
        prev=head
        cur=head.next
        adj=head.next.next
        prev.next=None
        while(cur!=None):
            cur.next=prev
            if(adj==None):
                return cur
            prev=cur
            cur=adj
            adj=adj.next
        return cur