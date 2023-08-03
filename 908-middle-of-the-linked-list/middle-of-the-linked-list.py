# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp1=head
        temp2=head
        while(temp2.next!=None):
            temp1=temp1.next
            temp2=temp2.next
            if(temp2==None):
                break
            temp2=temp2.next
            if(temp2==None):
                break
        return temp1
        