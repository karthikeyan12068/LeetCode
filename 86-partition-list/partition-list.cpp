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
    ListNode* partition(ListNode* head, int x) {
        ListNode* t=NULL;
        ListNode* temp=NULL;
        ListNode* t1=head;
        while(t1!=NULL){
            if(t1->val<x){
                if(temp==NULL){
                    temp=new ListNode(t1->val);
                    t=temp;
                }
                else{
                    t->next=new ListNode(t1->val);
                    t=t->next;
                }
            }
            t1=t1->next;
        }
        t1=head;
        while(t1!=NULL){
            if(t1->val>=x){
                if(temp==NULL){
                    temp=new ListNode(t1->val);
                    t=temp;
                }
                else{
                    t->next=new ListNode(t1->val);
                    t=t->next;
                }
            }
            t1=t1->next;
        }
        return temp;
    }
};