//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minOperations(long long int n) {
        // Code here
        long long int sum;
        if(n%2!=0){
            long long int n1=n/2;
            long long int a=2,d=2;
            sum=(n1*a)+(((n1-1)*d)/2)*n1;
        }
        else{
            long long int n1=n/2;
            long long int a=1,d=2;
            sum=(n1*a)+(((n1-1)*d)/2)*n1;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends