/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* t=head;
        while(t!=NULL){
            len++;
            t=t->next;
        }
        int actnodemoves=len-n,prevnode=actnodemoves-1;
        if(prevnode<0){
            return head->next;
        }
        ListNode *t1=head,*t2=head;
        while(actnodemoves--){
            t1=t1->next;
        }
        while(prevnode--){
            t2=t2->next;
        }
        t2->next=t1->next;
        return head;
    }
};