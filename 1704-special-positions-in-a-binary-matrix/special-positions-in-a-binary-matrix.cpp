class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int c=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                int f=0;
                if(mat[i][j]==1){
                    for(int k=0;k<mat.size();k++){
                        if(k!=i && mat[k][j]==1){
                            f=1;
                            break;
                        }
                    }
                    if(f==0){
                        for(int k=0;k<mat[0].size();k++){
                            if(k!=j && mat[i][k]==1){
                                f=1;
                                break;
                            }
                        }
                        if(f==0){
                            c++;
                        }
                    }
                }
            }
        }
        return c;
    }
};