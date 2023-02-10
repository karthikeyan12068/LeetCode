//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        unordered_map<char,int>m1;
        for(auto it:s){
            if(it=='b' || it=='a' || it=='l' || it=='o' || it=='n'){
                m1[it]++;
            }
        }
        int c=0;
        while(m1['b']>=1 && m1['a']>=1 && m1['l']>=2 && m1['o']>=2 && m1['n']>=1){
            m1['b']-=1;m1['a']-=1;m1['l']-=2;m1['o']-=2;m1['n']-=1;
            c++;
        }
        return c;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends