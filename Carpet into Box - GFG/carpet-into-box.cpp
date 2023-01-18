//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int l1=0,b1=0,l2=0,b2=0;
        int temp1=A;
        while(temp1>C){
            temp1/=2;
            l1++;
        }
        temp1=A;
        while(temp1>D){
            temp1/=2;
            b1++;
        }
        temp1=B;
        while(temp1>C){
            temp1/=2;
            l2++;
        }
        temp1=B;
        while(temp1>D){
            temp1/=2;
            b2++;
        }
        return min(l1+b2,b1+l2);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends