/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL){
            return NULL;
        }
        ListNode* slow=head,*fast=head;
        
        while(true){
            slow=slow->next;
            fast=fast->next;
            if(fast==NULL){
                return NULL;
            }
            fast=fast->next;
            if(fast==NULL){
                return NULL;
            }
            if(slow==fast){
                break;
            }
        }
        ListNode* ptr=head;
        while(slow!=ptr){
            ptr=ptr->next;
            slow=slow->next;
        }
        return ptr;
    }
};