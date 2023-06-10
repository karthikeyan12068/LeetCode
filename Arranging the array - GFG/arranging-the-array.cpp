//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            stack<int>s;
            int c=0;
            for(int i=0;i<n;i++){
                s.push(arr[i]);
                if(arr[i]<0){
                    c++;
                }
            }
            int l=0+c,r=n-1;
            while(n--){
                if(s.top()>=0){
                    arr[r]=s.top();
                    s.pop();
                    r--;
                }
                else{
                    l--;
                    arr[l]=s.top();
                    s.pop();
                }
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends