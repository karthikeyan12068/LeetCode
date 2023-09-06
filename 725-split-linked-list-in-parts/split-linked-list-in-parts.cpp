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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>v(k);
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        if(n<=k){
            temp=head;
            int i=0;
            while(temp!=NULL){
                v[i]=new ListNode(temp->val);
                temp=temp->next;
                i++;
            }
        }
        else{
            int rem=n%k;
            temp=head;
            int x=n/k;
            int j=0;

            while(temp!=NULL){
                ListNode* t=NULL;
                for(int i=0;i<x;i++){
                    if(v[j]==NULL){
                        v[j]=new ListNode(temp->val);
                        t=v[j];
                    }
                    else{
                        t->next=new ListNode(temp->val);
                        t=t->next;
                    }
                    temp=temp->next;
                }
                if(rem>0){
                    t->next=new ListNode(temp->val);
                    temp=temp->next;
                    rem--;
                }
                j++;
            }
        }
        return v;
    }
};