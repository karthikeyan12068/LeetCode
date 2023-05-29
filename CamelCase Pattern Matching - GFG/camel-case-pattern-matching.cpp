//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> d, string p) {
        vector<string>ans={"-1"};
        for(int i=0;i<N;i++){
            string temp=d[i];
            int ptr1=0,ptr2=0;
            int c=0;
            while(ptr1<temp.length() && c!=p.length()){
                if(toupper(temp[ptr1])==temp[ptr1]){
                    if(temp[ptr1]==p[ptr2]){
                        c++;
                        ptr2++;
                    }
                    else{
                        c=p.length()+1;
                    }
                }
                ptr1++;
            }
            if(c==p.length()){
                if(ans.back()=="-1"){
                    ans.pop_back();
                }
                ans.push_back(temp);
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
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends