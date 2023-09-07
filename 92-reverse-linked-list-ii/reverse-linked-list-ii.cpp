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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        ListNode* prev=head,*cur=head,*adj=head;
        for(int i=1;i<left;i++){
            prev=prev->next;
            cur=prev;
            adj=cur;
        }
        int x=right-left;
        cur=prev->next;
        adj=cur->next;
        ListNode* x1=prev;
        prev->next=NULL;
        while(x--){
            cur->next=prev;
            prev=cur;
            cur=adj;
            if(adj!=NULL){
                adj=adj->next;
            }
        }
        if(left!=1){
            ListNode* temp=head;
            int diff=left-1;
            diff--;
            while(diff--){
                temp=temp->next;
            }
            temp->next=prev;
        }
        x1->next=cur;
        if(left!=1){
            return head;
        }
        return prev;
    }
};