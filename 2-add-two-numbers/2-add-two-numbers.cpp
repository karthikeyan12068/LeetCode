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
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef vector<int> v_i;
typedef vector<long long int> v_ll;
typedef vector<pair<int,int>> vp_i;
typedef vector<pair<long long int,long long int>> vp_ll;
typedef map<int,int> m_i;
typedef map<long long int,long long int> m_ll;
typedef map<pair<int,int>,int> mp_i;
typedef map<pair<long long int,long long int>,long long int> mp_ll;
typedef set<int> s_i;
typedef set<long long int> s_ll;
typedef set<pair<int,int>> sp_i;
typedef set<pair<long long int,long long int>> sp_ll;
#define mp make_pair
#define fi first
#define se second
#define INF 2e18
#define sorts(v) sort((v).begin(),(v).end())
#define rev(v) reverse((v).begin(),(v).end())
#define count2(v,s) count((v).begin(),(v).end(),(s))
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define forn(a,b,c) for(ll (c)=(a);(c)<(b);(c)++)
#define forr(a,b,c) for(ll (c)=(a);(i)>=(b);(c)--)
#define rep1(s) for(auto &it:(s))
#define rep2(a,b,c) for(ll i=(a);i<(b);i+=(c))
ll binets_formula(ll n) {
    double sqrt5 = sqrt(5);
    ll F_n = (pow((1 + sqrt5), n) - pow((1 - sqrt5), n)) / (pow(2, n) * sqrt5);
    return F_n;
}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
string to_binary(ll val)
{
    return (std::bitset<30>(val).to_string());
}
ll to_decimal(const string& s)
{
    return (std::bitset<30>(s).to_ulong());
}
double log_a_to_base_b(double a, double b)
{
    return log(a) / log(b);
}
ll str_to_in(string s)
{
    stringstream geek(s);
    ll x = 0ll;
    geek >> x;
    return x;
}

ll sum_v(v_ll v1){
    ll sum=0;
    forn(0,v1.size(),i){
        sum+=v1[i];
    }
    return sum;
}
ll ceil(ll x, ll y) {
    ll ans = x % y == 0 ? x / y : x / y + 1;
    return ans;
}
ll pair_match_sum(v_ll v1,ll rem_sum,m_ll m1,ll n){
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(m1[rem_sum-v1[i]]>0){
            ans+=m1[rem_sum-v1[i]];
            if(abs(v1[i]-rem_sum)==v1[i]){
                ans--;
            }
        }
    }
    return (ans/2);
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* temp3=NULL;
        ListNode* temp4;
        
        while(temp1!=NULL || temp2!=NULL){
            if(temp1!=NULL && temp2!=NULL){
                int val1=temp1->val+temp2->val;
                if(temp3==NULL){
                    temp3=new ListNode(val1%10);
                    if(val1>=10){
                        temp3->next=new ListNode(1);
                    }
                    temp4=temp3;
                }
                else{
                    if(temp3->next!=NULL){
                        temp3=temp3->next;
                        temp3->val=(temp3->val+val1)%10;
                        if(val1+1>=10){
                            temp3->next=new ListNode(1);
                        }
                    }
                    else{
                       temp3->next=new ListNode(val1%10);
                        temp3=temp3->next;
                        if(val1>=10){
                            temp3->next=new ListNode(1);
                        }
                    }
                }
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else{
                
                if(temp1!=NULL){
                    cout<<temp1->val;
                    int val1=temp1->val;
                    if(temp3->next!=NULL){
                        temp3=temp3->next;
                        temp3->val=(temp3->val+val1)%10;
                        if(val1+1>=10){
                            temp3->next=new ListNode(1);
                        }
                    }
                    else{
                       temp3->next=new ListNode(val1%10); 
                        temp3=temp3->next;
                        if(val1>=10){
                            temp3->next=new ListNode(1);
                        }
                    }
                    temp1=temp1->next;
                }
                else{
                    int val1=temp2->val;
                    cout<<temp2->val;
                    if(temp3->next!=NULL){
                        temp3=temp3->next;
                        temp3->val=(temp3->val+val1)%10;
                        if(val1+1>=10){
                            temp3->next=new ListNode(1);
                        }
                    }
                    else{
                       temp3->next=new ListNode(val1%10); 
                        temp3=temp3->next;
                        if(val1>=10){
                            temp3->next=new ListNode(1);
                        }
                    }
                    temp2=temp2->next;
                }
            }
        }
        return temp4;
    }
};