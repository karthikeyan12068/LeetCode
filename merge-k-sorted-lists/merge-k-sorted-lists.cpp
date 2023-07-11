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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        multiset<int>s;
        ListNode* ans=NULL;
        for(int i=0;i<lists.size();i++){
            ListNode* t=lists[i];
            while(t!=NULL){
                s.insert(t->val);
                t=t->next;
            }
        }
        ListNode* temp;
        for(auto it:s){
            if(ans==NULL){
                ans=new ListNode(it);
                temp=ans;
            }
            else{
                temp->next=new ListNode(it);
                temp=temp->next;
            }
        }
        return ans;
    }
};