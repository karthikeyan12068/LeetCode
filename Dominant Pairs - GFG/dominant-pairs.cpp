//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        vector<int>v1,v2;
        int i;
        for(i=0;i<n/2;i++){
            v1.push_back(arr[i]);
        }
        for(i=i;i<n;i++){
            v2.push_back(arr[i]);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int s=0;
        for(int j=0;j<v2.size();j++){
            auto it=lower_bound(v1.begin(),v1.end(),v2[j]*5);
            int ind=it-v1.begin();
            s+=v1.size()-ind;
        }
        return s;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends