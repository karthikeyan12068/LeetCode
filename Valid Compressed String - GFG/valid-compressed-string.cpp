//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
        int count=0;
        int i1=0,i2=0;
        while(i1<S.length() && i2<T.length()){
            if(S[i1]!=T[i2] && isdigit(T[i2])){
                string counts="";
                while(i2!=T.length() && isdigit(T[i2])){
                    counts+=T[i2];
                    i2++;
                }
                count=stoi(counts);
                i1+=count;
            }
            else{
                if(S[i1]!=T[i2] && !isdigit(T[i2])){
                    return 0;
                }
                else{
                    i1++;
                    i2++;
                }
            }
        }
        //cout<<i1<<" "<<i2;
        if(i1==S.length() && i2==T.length()){
            return 1;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends