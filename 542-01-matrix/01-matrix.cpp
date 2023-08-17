class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    //mat[i][j]=-1;
                    q.push({i,j});
                }
                else{
                    mat[i][j]=-2;
                }
            }
        }
        int dis=0;
        vector<pair<int,int>>pos={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            dis++;
            int x=q.size();
            while(x--){
                auto node=q.front();
                q.pop();
                for(auto it:pos){
                    int x1=node.first+it.first;
                    int y1=node.second+it.second;
                    if(x1>=0 && x1<mat.size() && y1>=0 && y1<mat[0].size() && mat[x1][y1]==-2){
                        mat[x1][y1]=dis;
                        q.push({x1,y1});
                    }
                }
            }
        }
        return mat;
    }
};