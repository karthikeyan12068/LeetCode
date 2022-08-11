/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
string str(char c){
    string s;
    stringstream ss;
    ss << c;
    ss >> s;
    return s;
}
template<typename T>
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
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
void ret(TreeNode* root,vector<int>&v){
    if(root!=NULL){
        ret(root->left,v);
        v.push_back(root->val);
        ret(root->right,v);
    }
    
}
TreeNode* recover(TreeNode* root){
    vector<int>v1;
    ret(root,v1);
    int val1=-1,val2=-1;
    vector<int>v2;
    v2=v1;
    sorts(v2);
    forn(0,v1.size(),i){
        if(v1[i]!=v2[i]){
            if(val1==-1){
                val1=v1[i];
            }
            else{
                val2=v1[i];
                break;
            }
        }
    }
    
    stack<TreeNode*>stack;
    TreeNode* cur=root;
    TreeNode* temp1=NULL;
    TreeNode* temp2=NULL;
    while(!stack.empty() || cur!=NULL){
        if(cur!=NULL){
            stack.push(cur);
            if(cur!=NULL && (cur->val==val1 || cur->val==val2)){
                if(temp1==NULL){
                    temp1=cur;
                }
                else{
                    temp2=cur;
                }
            }
            cur=cur->left;
        }
        else{
            cur=stack.top();
            stack.pop();
            cur=cur->right;
            if(cur!=NULL && (cur->val==val1 || cur->val==val2)){
                if(temp1==NULL){
                    temp1=cur;
                }
                else{
                    temp2=cur;
                }
            }
        }
    }
    swap(temp1->val,temp2->val);
    return root;
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        root=recover(root);
        
    }
};