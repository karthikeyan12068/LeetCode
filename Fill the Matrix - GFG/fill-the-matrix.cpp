//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        int iter=-1;
        queue<pair<int,int>>q;
        x--;y--;
        q.push({x,y});
        vector<vector<int>>vis(N,vector<int>(M,-1));
        while(!q.empty()){
            int x=q.size();
            for(int i=0;i<x;i++){
                pair<int,int>p=q.front();
                vis[p.first][p.second]=1;
                
                q.pop();
                int topx=p.first-1,topy=p.second;
                int leftx=p.first,lefty=p.second-1;
                int rightx=p.first,righty=p.second+1;
                int botx=p.first+1,boty=p.second;
                if(topx>=0 && topy>=0 && topx<=N-1 && topy<=M-1 && vis[topx][topy]==-1){
                    vis[topx][topy]=1;
                    q.push({topx,topy});
                }
                if(rightx>=0 && righty>=0 && rightx<=N-1 && righty<=M-1 && vis[rightx][righty]==-1){
                    vis[rightx][righty]=1;
                    q.push({rightx,righty});
                }
                if(leftx>=0 && lefty>=0 && leftx<=N-1 && lefty<=M-1 && vis[leftx][lefty]==-1){
                    vis[leftx][lefty]=1;
                    q.push({leftx,lefty});
                }
                if(botx>=0 && boty>=0 && botx<=N-1 && boty<=M-1 && vis[botx][boty]==-1){
                    vis[botx][boty]=1;
                    q.push({botx,boty});
                }
            }
            
            iter++;
        }
        return iter;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends