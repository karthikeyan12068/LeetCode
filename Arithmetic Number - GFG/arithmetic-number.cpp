//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        if(C==0){
            if(A==B){
                return 1;
            }
            return 0;
        }
        double a=(double)((double)B-(double)A)/(double)C;
        
        if(ceil(a)==floor(a)){
            if(ceil(a)+1>=1){
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends