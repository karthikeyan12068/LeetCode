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
    
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp=list1,*prev=list1;
        b=b-a;
        while(a!=0){
            prev=temp;
            temp=temp->next;
            a--;
        }
        ListNode* start=prev;
        while(b--){
            temp=temp->next;
            
        }
        temp=temp->next;
        prev->next=temp;
        //cout<<temp->val;
        ListNode* end=temp;
        if(list2==NULL){
            return list1;
        }
        ListNode* t=list2;
        while(t->next!=NULL){
            t=t->next;
        }
        start->next=list2;
        t->next=end;
        return list1;
    }
};