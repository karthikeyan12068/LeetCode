class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;

        map<pair<int,int>,int>m1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    m1[{i,j}]++;
                    grid[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>>pos={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            int x=q.size();
            while(x--){
                auto node=q.front();
                q.pop();
                for(auto it:pos){
                    int x1=node.first+it.first;
                    int y1=node.second+it.second;
                    if(x1>=0 && y1>=0 && x1<grid.size() && y1<grid[0].size() && m1[{x1,y1}]==0){
                        m1[{x1,y1}]++;
                        grid[x1][y1]=grid[node.first][node.second]+1;
                        q.push({x1,y1});
                    }
                }
            }
        }
        int ans=INT_MAX;
        priority_queue<pair<int,pair<int,int>>>q1;
        m1.clear();
        q1.push({grid[grid.size()-1][grid[0].size()-1],{grid.size()-1,grid[0].size()-1}});
        
        while(true){
            auto node=q1.top().second;
            int manhat=q1.top().first;
            
            m1[node]++;
            q1.pop();
            ans=min(ans,manhat);
            if(node.first==0 && node.second==0){
                break;
            }
            for(auto it:pos){
                int x1=node.first+it.first;
                int y1=node.second+it.second;
                if(x1>=0 && y1>=0 && x1<grid.size() && y1<grid[0].size() && m1[{x1,y1}]==0){
                    
                    m1[{x1,y1}]++;
                    q1.push({grid[x1][y1],{x1,y1}});
                }
            }
        }
        
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};