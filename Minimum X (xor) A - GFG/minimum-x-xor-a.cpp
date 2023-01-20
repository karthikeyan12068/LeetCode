//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int temp=b,c=0;
        while(temp!=0){
            if(temp%2==1){
                c++;
            }
            temp/=2;
        }
        string set="";
        temp=a;
        while(temp!=0){
            set=to_string(temp%2)+set;
            temp/=2;
        }
        string ret="";
        for(int i=0;i<set.length();i++){
            if(set[i]=='1'){
                if(c>0){
                    c--;
                    ret=ret+"1";
                }
                else{
                    ret=ret+"0";
                }
            }
            else{
                ret=ret+"0";
            }
        }
        if(c!=0){
            for(int i=ret.length()-1;i>=0;i--){
                if(ret[i]=='0'){
                    ret[i]='1';
                    c--;
                    if(c==0){
                        break;
                    }
                }
            }
        }
        int ans=0;
        int st=0;
        for(int i=ret.length()-1;i>=0;i--){
            if(ret[i]!='0'){
                ans+=pow(2,st);
            }
            st++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends