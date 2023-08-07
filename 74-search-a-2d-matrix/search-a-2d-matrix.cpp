class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()-1;
        int ansx=0;
        while(l<=r){
            int mid=(l+r)/2;
            int x=mid,y=matrix[0].size()-1;
            if(matrix[x][y]<target){
                l=mid+1;
            }
            else{
                ansx=x;
                r=mid-1;
            }
        }
        int ind=lower_bound(matrix[ansx].begin(),matrix[ansx].end(),target)-matrix[ansx].begin();
        if(ind<matrix[0].size() && matrix[ansx][ind]==target){
            return true;
        }
        return false;
    }
};