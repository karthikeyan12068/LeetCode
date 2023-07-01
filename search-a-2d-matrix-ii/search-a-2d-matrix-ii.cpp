class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=matrix[0].size()-1;i>=0;i--){
            if(matrix[0][i]<=target){
                int l=0,r=matrix.size()-1;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(matrix[mid][i]==target){
                        return true;
                    }
                    if(matrix[mid][i]>target){
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
            }
        }
        return false;
    }
};