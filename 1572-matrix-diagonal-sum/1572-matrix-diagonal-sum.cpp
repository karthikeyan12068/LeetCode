class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i1=0,j1=0,i2=0,j2=mat[0].size()-1;
        int s=0;
        while(i1<mat.size()){
            s+=mat[i1][j1];
            s+=mat[i2][j2];
            i1++;
            i2++;
            j1++;
            j2--;
        }
        if(mat.size()%2!=0){
            s-=mat[mat.size()/2][mat[0].size()/2];
        }
        return s;
    }
};