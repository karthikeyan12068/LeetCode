# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp=head
        dict={}
        while(temp!=None):
            if(temp in dict):
                return temp
            dict[temp]=1
            temp=temp.next
        return None
