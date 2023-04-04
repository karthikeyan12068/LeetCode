//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
        // Code here
        unordered_map<int,int>m1;
        for(auto it:arr){
            m1[it]++;
        }
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=1;j<=sqrt(arr[i]);j++){
                if(arr[i]%j==0){
                    int val1=j;
                    int val2=arr[i]/j;
                    if(val1!=arr[i] && m1[val1]!=0 || val2!=arr[i] && m1[val2]!=0){
                        ans++;
                        break;
                    }
                    else{
                        if(m1[val1]>1 || m1[val2]>1){
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends