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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=NULL,*ptr1=list1,*ptr2=list2,*ansp=NULL;
        while(ptr1!=NULL || ptr2!=NULL){
            
            if(ptr1!=NULL && ptr2!=NULL){
                if(ptr1->val<=ptr2->val){
                    ListNode* node=new ListNode(ptr1->val);
                    ptr1=ptr1->next;
                    if(ans==NULL){
                        ans=node;
                        ansp=ans;
                    }
                    else{
                        ansp->next=node;
                        ansp=ansp->next;
                    }
                }
                else{
                    ListNode* node=new ListNode(ptr2->val);
                    ptr2=ptr2->next;
                    if(ans==NULL){
                        ans=node;
                        ansp=ans;
                    }
                    else{
                        ansp->next=node;
                        ansp=ansp->next;
                    }
                }
            }
            else{
                if(ptr2==NULL){
                    cout<<1;
                    ListNode* node=new ListNode(ptr1->val);
                    ptr1=ptr1->next;
                    if(ans==NULL){
                        ans=node;
                        ansp=ans;
                    }
                    else{
                        ansp->next=node;
                        ansp=ansp->next;
                    }
                }
                else{
                    cout<<1;
                    ListNode* node=new ListNode(ptr2->val);
                    ptr2=ptr2->next;
                    if(ans==NULL){
                        ans=node;
                        ansp=ans;
                    }
                    else{
                        ansp->next=node;
                        ansp=ansp->next;
                    }
                }
            }
        }
        return ans;
    }
};