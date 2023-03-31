//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            for(int i=0;i<n-1;i++){
                if(a[i]%2==0 && a[i+1]%2==0 || a[i]%2!=0 && a[i+1]%2!=0){
                    int j=i;
                    for(j=i;j<n;j++){
                        if(a[i]%2==0 && a[j]%2!=0 || a[i]%2!=0 && a[j]%2==0){
                            break;
                        }
                    }
                    sort(a.begin()+i,a.begin()+j,greater<int>());
                    i=j-1;
                }
            }
            return a;
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
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends