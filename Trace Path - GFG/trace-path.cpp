//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        
        int maxc=m-1,maxr=n-1;
        int l=maxc,r=maxc,u=maxr,d=maxr;
        int f=1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R'){
                r--;
                if(l!=maxc){
                    l++;
                }
            }
            if(s[i]=='L'){
                l--;
                if(r!=maxc){
                    r++;
                }
            }
            if(s[i]=='U'){
               u--;
               if(d!=maxr){
                   d++;
               }
            }
            if(s[i]=='D'){
               d--;
               if(u!=maxr){
                   u++;
               }
            }
            if(l<0 || l>=m || r<0 || r>=m || u<0 || u>=n || d<0 || d>=n){
                //cout<<l<<" "<<r<<" "<<u<<" "<<d<<'\n';
                f=0;
                break;
            }
        }
        return f;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends