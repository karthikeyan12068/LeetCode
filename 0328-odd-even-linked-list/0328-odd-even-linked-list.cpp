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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* head1=NULL,*head2=NULL,*temp1=NULL,*temp2=NULL;
        int i=0;
        ListNode* temp=head;
        while(temp!=NULL){
            if(i%2==0){
                if(head1==NULL){
                    head1=new ListNode(temp->val);
                    temp1=head1;
                }
                else{
                    temp1->next=new ListNode(temp->val);
                    temp1=temp1->next;
                }
            }
            else{
               if(head2==NULL){
                    head2=new ListNode(temp->val);
                    temp2=head2;
                }
                else{
                    temp2->next=new ListNode(temp->val);
                    temp2=temp2->next;
                } 
            }
            i++;
            temp=temp->next;
        }
        if(head1!=NULL){
            if(head2!=NULL){
                temp1->next=head2;
                return head1;
            }
            else{
                return head1;
            }
        }
        else{
            return head2;
        }
    }
};