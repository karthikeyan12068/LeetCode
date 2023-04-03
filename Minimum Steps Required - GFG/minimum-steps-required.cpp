//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int sum1=0,sum2=0,c1=0,c2=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='a'){
            int j;
            for(j=i;j<str.length();j++){
                if(str[j]!='a'){
                    break;
                }
            }
            sum1++;
            i=j-1;
        }
        else{
            c1=1;
        }
    }
    if(c1==1){
        sum1++;
    }
    for(int i=0;i<str.length();i++){
        if(str[i]=='b'){
            int j;
            for(j=i;j<str.length();j++){
                if(str[j]!='b'){
                    break;
                }
            }
            sum2++;
            i=j-1;
        }
        else{
            c2=1;
        }
    }
    if(c2==1){
        sum2++;
    }
    return min(sum1,sum2);
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends