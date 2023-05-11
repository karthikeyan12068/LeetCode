//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int n=s.length();
        vector<int>v;
        for(int i=0;i<s.length();i++){
            if(s[i]!='?'){
                v.push_back(i);
                if(s[n-i-1]=='?'){
                    s[n-i-1]=s[i];
                }
                else{
                    if(s[i]!=s[n-i-1]){
                        return -1;
                    }
                }
            }
        }
        
        for(int i=0;i<v.size();i++){
            int l=v[i]-1;
            int k=v[i]+1;
            for(int j=l;j>=0;j--){
                if(s[j]!='?'){
                    break;
                }
                else{
                    s[j]=s[v[i]];
                }
            }
            for(int j=k;j<s.length();j++){
                if(s[j]!='?'){
                    break;
                }
                else{
                    s[j]=s[v[i]];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-i-1]){
                s[i]=s[n-i-1];
            }
        }
        int a=0;
        for(int i=1;i<s.length();i++){
            int c1=(int)s[i];
            int c2=(int)s[i-1];
            a+=abs(c2-c1);
        }
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends