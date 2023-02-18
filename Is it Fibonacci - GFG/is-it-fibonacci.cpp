//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> arr) {
        vector<long long>prefixsum;
        long long sum=0;
        for(auto it:arr){
            sum+=it;
            prefixsum.push_back(sum);
        }
        int ind=0;
        for(int i=0;i<N-K;i++){
            if(i==0){
                arr.push_back(sum);
            }
            else{
                arr.push_back(sum-prefixsum[ind]);
                ind++;
            }
            sum+=arr.back();
            prefixsum.push_back(sum);
        }
        
        return arr[arr.size()-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends