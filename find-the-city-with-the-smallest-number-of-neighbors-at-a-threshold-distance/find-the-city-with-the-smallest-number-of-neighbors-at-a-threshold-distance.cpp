class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>cost(n,vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++){
            cost[edges[i][0]][edges[i][1]]=edges[i][2];
            cost[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    cost[i][j]=0;
                }
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        int ans=-1,c=INT_MAX;
        for(int i=0;i<n;i++){
            int len=0;
            for(int j=0;j<n;j++){
                if(cost[i][j]<=distanceThreshold){
                    len++;
                }
            }
            if(c==len){
                ans=max(ans,i);
            }
            else{
                if(c>len){
                    c=len;
                    ans=i;
                }
            }
        }
        return ans;
    }
};