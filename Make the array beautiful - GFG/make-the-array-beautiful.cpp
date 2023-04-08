//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int>ans;
        for(int i=0;i<arr.size();i++){
            if(ans.empty()){
                ans.push(arr[i]);
            }
            else{
                if(ans.top()>=0 && arr[i]>=0 || ans.top()<0 && arr[i]<0){
                    ans.push(arr[i]);
                }
                else{
                    ans.pop();
                }
            }
        }
        vector<int>a;
        while(!ans.empty()){
            a.push_back(ans.top());
            ans.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends