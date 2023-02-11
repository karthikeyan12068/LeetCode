class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        int vis[grid.size()][grid.size()];
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({i,j});
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int dis=-1;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                pair<int,int>cur=q.front();
                q.pop();
                for(auto it:dir){
                    int x=cur.first+it.first;
                    int y=cur.second+it.second;
                    if(x>=0 && y>=0 && x<grid.size() && y<grid.size() && vis[x][y]==0){
                        vis[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            dis++;
        }
        if(dis==0){
            return -1;
        }
        return dis;
    }
};