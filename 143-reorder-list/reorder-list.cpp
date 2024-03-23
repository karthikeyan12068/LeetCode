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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        if(head->next->next==NULL){
            swap(head->val,head->next->val);
            return head;
        }
        
        ListNode* prev=head,*cur=head->next,*nxt=head->next->next;
        prev->next=NULL;
        while(cur!=NULL){
            //cout<<prev->val<<' '<<cur->val<<' '<<nxt->val<<'\n';
            cur->next=prev;
            if(nxt==NULL){
                return cur;
            }
            prev=cur;
            cur=nxt;
            nxt=nxt->next;
        }
    
        //cout<<cur->val<<'\n';
        return cur;
    }
    void reorderList(ListNode* head) {
        ListNode* first=head,*second=head;
        ListNode* prev=head,*t=head,*ans=head;
        while(second!=NULL){
            prev=first;
            first=first->next;
            second=second->next;
            if(second!=NULL){
                second=second->next;
            }
        }
        
        prev->next=NULL;
        first=reverseList(first);
        
        while(first!=NULL){
            ListNode* nxt=t->next;
            t->next=new ListNode(first->val);
            t->next->next=nxt;
            t=nxt;
            first=first->next;
        }
        
    }
};