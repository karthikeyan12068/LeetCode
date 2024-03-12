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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int,int>m;
        ListNode* temp=new ListNode(0);
        temp->next=head;
        int start=0,sum=0;
        map<int,int>m2;
        while(temp!=NULL){
            sum+=temp->val;
            //cout<<sum<<'\n';
            auto it1=m.find(sum);
            if(it1==m.end()){
                m[sum]=start;
            }
            else{
            
                int init=it1->second;
                m2[init+1]=start;
                m.erase(sum);
                m[sum]=start;
            }
            temp=temp->next;
            start++;
        }
        /*cout<<m[1]<<'\n';
        for(auto it:m2){
            cout<<it.first<<' '<<it.second<<'\n';
        }*/
        auto it=m2.begin();
        /*while(it!=m2.end()){
            if(it!=m2.begin()){
                auto before=it;
                before--;
                if(before->second>=it->first && before->first<=it->first){
                    
                    auto temp=it;
                    it++;
                    if(before->second-before->first>=temp->second-temp->first){
                        m2.erase(temp);
                    }
                    else{
                        m2.erase(before);
                    }
                }
                else{
                    it++;
                }
            }
            else{
                it++;
            }
        }*/
        /*for(auto it:m2){
            cout<<it.first<<' '<<it.second<<'\n';
        }*/
        ListNode* ans=NULL,*t2=ans;
        //head=head->next;
        ListNode* t1=head;
        start=1;
        while(t1!=NULL){
            auto f=m2.find(start);
            
            if(f==m2.end()){
                if(ans==NULL){
                    ans=new ListNode(t1->val);
                    t2=ans;
                }
                else{
                    t2->next=new ListNode(t1->val);
                    t2=t2->next;
                }
                t1=t1->next;
                start++;
            }
            else{
                while(start<=f->second){
                    start++;
                    t1=t1->next;
                }
            }
        }
        return ans;
    }
};