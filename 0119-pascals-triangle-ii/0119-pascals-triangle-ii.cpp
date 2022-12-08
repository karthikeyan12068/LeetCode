class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>>v1(n+1);
        for(int i=0;i<=n;i++){
            if(i==0){
                v1[0]={1};
            }
            if(i==1){
                v1[1]={1,1};
            }
            if(i>1){
                v1[i]={1};
                for(int j=1;j<v1[i-1].size();j++){
                    v1[i].push_back(v1[i-1][j]+v1[i-1][j-1]);
                }
                v1[i].push_back(1);
            }
        }
        return v1[n];
    }
};