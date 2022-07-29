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
    int myAtoi(string s) {
        ll space=0,p=0,m=0;
        string fin="";
        int z=0;
        ll ind=-1;
        forn(0,s.length(),i){
            if(s[i]=='0' && fin.length()==0){
                if(i-1>=0 && s[i-1]=='-'){
                    ind=i-1;
                }
                z=1;
                continue;
            }
            if(s[i]==' '){
                if(fin.length()>0 || z!=0){
                    break;
                }
            }
            if(s[i]=='+' || s[i]=='-'){
                
                if(p>0 || m>0){
                    break;
                }
                else{
                    if(s[i]=='+'){
                        p=1;
                    }
                    else{
                        m=1;
                    }
                }
                if(fin.length()>0 || z!=0){
                    break;
                }
            }
            else{
                if(int(s[i])>=48 && int(s[i])<=57){
                    if(fin.length()==0){
                        if(i-1>=0 && s[i-1]=='-'){
                            ind=i;
                        }
                    }
                    fin+=s[i];
                }
                else{
                    if(s[i]==' '){
                        if(fin.length()>0 || z!=0 || p>0 || m>0)
                            break;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        
        if(fin.length()>10){
            if(ind==-1 && s[0]!='-'){
                return 2147483647;
            }
            else{
                return -2147483648;
            }
        }
        else{
            
            ll x=str_to_in(fin);
            
            if(ind!=-1 || s[0]=='-'){
                x*=-1;
            }
        
            if(x>=2147483647){
                
                return 2147483647;
            }
            if(x<=-2147483648){
                
                return -2147483648;
            }
            return (int)x;
        }
    }
};