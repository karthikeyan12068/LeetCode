//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
       string temp="";
       for(int i=0;i<x.length();i++){
           temp+=x[i];
           if(temp.length()>=2){
               int a=stoi(temp);
               int rem=a%11;
               temp="";
               if(rem!=0){
                   temp+=to_string(rem);
               }
           }
       }
       if(temp==""){
           return 0;
       }
       int ans=stoi(temp);
       return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends