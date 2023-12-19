class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<pair<int,int>>v={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
        vector<vector<int>>ans(img.size(),vector<int>(img[0].size(),0));
        for(int i=0;i<img.size();i++){
            for(int j=0;j<img[0].size();j++){
                int sum=img[i][j];
                int c=1;
                for(auto it:v){
                    int x1=i+it.first,y1=j+it.second;
                    if(x1>=0 && x1<img.size() && y1>=0 && y1<img[0].size()){
                        c++;
                        sum+=img[x1][y1];
                    }
                }
                ans[i][j]=sum/c;
            }
        }
        return ans;
    }
};