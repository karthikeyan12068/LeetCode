class Solution {
public:
    #define min3(a,b,c)     min(a,min(b,c))
    int countSquares(vector<vector<int>>& matrix) {
        int sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    int top=0,left=0,diag=0;
                    if(i-1>=0){
                        top=matrix[i-1][j];
                    }
                    if(j-1>=0){
                        left=matrix[i][j-1];
                    }
                    if(i-1>=0 && j-1>=0){
                        diag=matrix[i-1][j-1];
                    }
                    matrix[i][j]+=min3(top,left,diag);
                    sum+=matrix[i][j];
                }
            }
        }
        return sum;
    }
};