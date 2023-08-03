# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None or head.next.next==None:
            return head
        c=head
        x=0
        while c!=None:
            c=c.next
            x+=1
        prev=head
        cur=head.next.next
        while cur!=None:
            temp=prev.next
            prev.next=ListNode(cur.val)
            prev.next.next=temp
            if cur.next==None:
                cur=None
                break
            temp1=cur
            temp1=temp1.next.next
            cur.val=cur.next.val
            cur.next=cur.next.next
            cur=temp1
            prev=prev.next
        if(x%2!=0):
            t1=head
            t2=head
            x=0
            while t1.next!=None:
                t2=t1
                t1=t1.next
                x+=1
            t2.next=None
        return head


    