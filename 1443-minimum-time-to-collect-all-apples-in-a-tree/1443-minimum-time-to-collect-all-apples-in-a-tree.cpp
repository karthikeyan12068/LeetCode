class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        map<int,int>m1;
        vector<int>vis(n,0);
        for(int i=0;i<edges.size();i++){
            if(vis[edges[i][1]]==0){
                vis[edges[i][1]]=-1;
                m1[edges[i][1]]=edges[i][0];
            }
            else{
                vis[edges[i][0]]=-1;
                m1[edges[i][0]]=edges[i][1];
            }
        }
        vis[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(hasApple[i]){
                int j=i;
                while(j!=0 && vis[j]==-1){
                    sum+=2;
                    vis[j]=0;
                    j=m1[j];
                }
            }
        }
        return sum;
    }
};