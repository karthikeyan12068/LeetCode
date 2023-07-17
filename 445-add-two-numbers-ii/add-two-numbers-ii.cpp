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
 ListNode* rev(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* prev=head;
    ListNode* cur=head->next;
    ListNode* adj=cur->next;
    prev->next=NULL;
    while(cur!=NULL){
        cur->next=prev;
        prev=cur;
        head=cur;
        cur=adj;
        if(cur!=NULL){
            adj=adj->next;
        }
    }
    return head;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=rev(l1);
        l2=rev(l2);
        int change=0;
        ListNode* ans=NULL;
        ListNode* temp;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL && l2!=NULL){
                int x=l1->val+l2->val+change;
                if(x>=10){
                    change=1;
                    x%=10;
                }
                else{
                    change=0;
                }
                if(ans==NULL){
                    ans=new ListNode(x);
                    temp=ans;
                }
                else{
                    temp->next=new ListNode(x);
                    temp=temp->next;
                }
                l1=l1->next;
                l2=l2->next;
            }
            else{
                if(l1!=NULL){
                    int x=l1->val+change;
                    
                    if(x>=10){
                        change=1;
                        x%=10;
                    }
                    else{
                        change=0;
                    }
                    if(ans==NULL){
                        ans=new ListNode(x);
                        temp=ans;
                    }
                    else{
                        temp->next=new ListNode(x);
                        temp=temp->next;
                    }  
                    l1=l1->next;
                }
                if(l2!=NULL){
                    int x=l2->val+change;
                    
                    if(x>=10){
                        change=1;
                        x%=10;
                    }
                    else{
                        change=0;
                    }
                    if(ans==NULL){
                        ans=new ListNode(x);
                        temp=ans;
                    }
                    else{
                        temp->next=new ListNode(x);
                        temp=temp->next;
                    } 
                    l2=l2->next; 
                }
            }
        }
        if(change!=0){
            temp->next=new ListNode(1);
        }
        ans=rev(ans);
        return ans;
    }
};