//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        stack<pair<int,int>>s;
        vector<long long>v(n,-1);
        for(int i=0;i<n;i++){
            if(s.empty()){
                s.push({arr[i],i});
            }
            else{
                while(s.top().first<arr[i]){
                    v[s.top().second]=arr[i];
                    s.pop();
                    if(s.empty()){
                        break;
                    }
                }
                s.push({arr[i],i});
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends