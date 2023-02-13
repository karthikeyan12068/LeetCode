//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        vector<vector<int>>v(N,vector<int>(3,INT_MAX));
        v[0][0]=colors[0][0];v[0][1]=colors[0][1];v[0][2]=colors[0][2];
        for(int i=1;i<N;i++){
            for(int j=0;j<3;j++){
                v[i][j]=colors[i][j]+min(v[i-1][(j+1)%3],v[i-1][(j+2)%3]);
            }
        }
        int min1=INT_MAX;
        for(int j=0;j<3;j++){
            min1=min(min1,v[N-1][j]);
        }
        return min1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends