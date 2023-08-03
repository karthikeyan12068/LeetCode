# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head==None or head.next==None:
            return None
        t1=head
        c=0
        while t1!=None:
            t1=t1.next
            c=c+1
        rem=c-n
        t1=head
        t2=head
        while(rem>0):
            t2=t1
            t1=t1.next
            rem-=1
        
        if t1.next==None:
            t2.next=None
        else:
            t1.val=t1.next.val
            t1.next=t1.next.next
        return head
