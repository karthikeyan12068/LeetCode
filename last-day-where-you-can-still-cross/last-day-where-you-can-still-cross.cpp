class Solution {
public:
    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
        int l=0,r1=cells.size()-1;
        
        /*vector<vector<int>>grid(r,vector<int>(c,0));
        for(int i=0;i<cells.size();i++){
            grid[cells[i][0]-1][cells[i][1]-1]=1;
            m1[i]=grid;
        }*/
        int ans=INT_MAX;
        vector<pair<int,int>>pos={{0,1},{0,-1},{1,0},{-1,0}};
        while(l<=r1){
            int mid=(l+r1)/2;
            vector<vector<int>>grid(r,vector<int>(c,0));
            for(int i=0;i<=mid;i++){
                grid[cells[i][0]-1][cells[i][1]-1]=1;
                
            }
            queue<pair<int,int>>q;
            for(int i=0;i<c;i++){
                if(grid[0][i]==0){
                    q.push({0,i});
                }
            }
            int f=0;
            while(!q.empty()){
                int x1=q.size();
                while(x1--){
                    auto node=q.front();
                    q.pop();
                    for(auto it:pos){
                        int x=node.first+it.first;
                        int y=node.second+it.second;
                        if(x>=0 && x<r && y>=0 && y<c && grid[x][y]==0){
                            grid[x][y]=1;
                            q.push({x,y});
                            if(x==r-1){
                                f=1;
                                break;
                            }
                        }
                    }
                }
                if(f==1){
                    break;
                }
            }
            if(f==1){
                ans=mid;
                l=mid+1;
            }
            else{
                r1=mid-1;
            }
        }
        return ans+1;
    }
};