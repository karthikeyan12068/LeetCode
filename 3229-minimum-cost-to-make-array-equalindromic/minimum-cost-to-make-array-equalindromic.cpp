#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
typedef priority_queue<ll> maxheap;
typedef priority_queue <ll, vector<ll>, greater<>> minheap;
#define mp make_pair
#define fi first
#define se second
#define INF 2e18
#define sorts(v) sort((v).begin(),(v).end())
#define rev(v) reverse((v).begin(),(v).end())
#define count2(v,s) count((v).begin(),(v).end(),(s))
#define finds(v,s) find((v).begin(),(v).end(),(s))
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define forn(a,b,c) for(ll (c)=(a);(c)<(b);(c)++)
#define forr(a,b,c) for(ll (c)=(a);(i)>=(b);(c)--)
#define rep1(s) for(auto &it:(s))
#define rep2(s) for(auto it=(s).begin();it!=(s).end();it++)
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void tokenize(string const &str, const char* delim,vector<string> &out)
{
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr)
    {
        out.push_back(string(token));
        token = strtok(nullptr, delim);
    }
}
vector<ll> str_p(string data){
    v_ll trav;
    ll i;
    stringstream ss(data);
    while (ss >> i) {
        trav.push_back(i);
        ss.ignore(1);
    }
    return trav;
}
ll factorial(ll n)
{
    // single line to find factorial
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}
string multiline(string s){
    getline(cin, s);
    //rev(s);
    return s;
}
string str(char c){
    string s;
    stringstream ss;
    ss << c;
    ss >> s;
    return s;
}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
string to_binary(ll val)
{
    string binary = bitset<30>(val).to_string();
    return binary;
}
ll to_decimal(const string& s)
{
    return (bitset<50>(s).to_ulong());
}
double log_a_to_base_b(double a, double b)
{
    return log(a) / log(b);
}
bool isprime(int x) {if (x == 1) return false; for (int i = 2; i * i <= x; ++i) {if (x % i == 0) return false; } return true; }
ll str_to_in(string s)
{
    stringstream geek(s);
    ll x = 0ll;
    geek >> x;
    return x;
}
bool hdp(double z) {
    if (ceil((float) z / 1.0) == floor((float) z / 1.0)) {
        return false;
    }
    return true;
}
ll sum_v(v_ll v1){
    ll sum=0;
    forn(0,v1.size(),i){
        sum+=v1[i];
    }
    return sum;
}


class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        sorts(nums);
        ll ans1=LONG_MAX,ans2=LONG_MAX;
        ll med_val=0;
        
        v_ll pref(nums.size());
        pref[0]=nums[0];
        forn(1,nums.size(),i){
            pref[i]=nums[i]+pref[i-1];
        }
        
        ll sum=nums[nums.size()/2];
        ll val1=sum,val2=sum+1;
        int f1=0,f2=0;
        
        while(f1==0 || f2==0){
            if(val1>0 && f1==0){
                string s1=to_string(val1);
                string s2=s1;
                rev(s2);
                if(s1==s2){
                    
                    ll t1=0;
                    auto it=lower_bound(nums.begin(),nums.end(),val1);
                    if(it==nums.end()){
                        ll tcs=val1*nums.size();
                        t1+=abs(pref.back()-tcs);
                        if(ans1>t1){
                            ans1=t1;
                            
                        }
                        else{
                            f1=1;
                        }
                    }
                    else{

                        ll ind=it-nums.begin();
                        ll tcs1=val1*(nums.size()-ind),tcs2=val1*ind;
                        
                        t1+=abs(((pref.back()-pref[ind])+nums[ind])-tcs1);
                        t1+=abs(pref[ind]-nums[ind]-tcs2);
                        
                        if(ans1>t1){
                            ans1=t1;
                        }
                        else{
                            f1=1;
                        }
                    }
                }
                val1--;
            }
            else{
                f1=1;
            }
            if(val2<=1000000000 && f2==0){
                string s1=to_string(val2);
                string s2=s1;
                rev(s2);
                if(s1==s2){
                    ll t1=0;
                    auto it=lower_bound(nums.begin(),nums.end(),val2);
                    if(it==nums.end()){
                        ll tcs=val2*nums.size();
                        t1=abs(pref.back()-tcs);
                        if(ans2>t1){
                            ans2=t1;
                            
                        }
                        else{
                            f2=1;
                        }
                    }
                    else{
                        ll ind=it-nums.begin();
                        ll tcs1=val2*(nums.size()-ind),tcs2=val2*ind;
                        t1+=abs(((pref.back()-pref[ind])+nums[ind])-tcs1);
                        t1+=abs(pref[ind]-nums[ind]-tcs2);
                        if(ans2>t1){
                            ans2=t1;
                        }
                        else{
                            f2=1;
                        }
                    }
                }
                val2++;
                
            }
            else{
                f2=1;
            }
        }
        return min(ans1,ans2);
    }
};