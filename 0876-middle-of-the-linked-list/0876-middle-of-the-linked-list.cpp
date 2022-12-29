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
    ListNode* middleNode(ListNode* head) {
        ListNode* h1=head;
        ListNode* h2=head;
        h2=h2->next;
        int f=0,a=0,b=0;
        while(true){
            if(h2==NULL){
                break;
            }
            h1=h1->next;
            h2=h2->next;
            if(h2==NULL){
                break;
            }
            h2=h2->next;
            if(h2==NULL){
                break;
            }
        }
        return h1;
    }
};