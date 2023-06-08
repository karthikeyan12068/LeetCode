//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        string ans="";
        if(N>=2){
            vector<vector<int>>adj(K);
            for(int i=0;i<N-1;i++){
                string s1=dict[i];
                string s2=dict[i+1];
                int i1=0,i2=0;
                while(i1<s1.length() && i2<s2.length()){
                    if(s1[i1]!=s2[i2]){
                        adj[s1[i1]-'a'].push_back(s2[i2]-'a');
                        break;
                    }
                    i1++;
                    i2++;
                }
            }
            vector<int>indeg(K);
            for(int i=0;i<K;i++){
                for(auto it:adj[i]){
                    indeg[it]++;
                }
            }
            queue<int>q;
            for(int i=0;i<K;i++){
                if(indeg[i]==0){
                    q.push(i);
                }
            }
            while(!q.empty()){
                int x=q.size();
                while(x--){
                    int node=q.front();
                    q.pop();
                    ans+=(char)(node+'a');
                    for(auto it:adj[node]){
                        indeg[it]--;
                        if(indeg[it]==0){
                            q.push(it);
                        }
                    }
                }
            }
        }
        else{
            map<char,int>m1;
            for(auto it:dict[0]){
                if(m1[it]==0){
                    ans+=it;
                    m1[it]++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends