class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int j=0;
        int r=strs.size(),c=strs[0].size();
        int c1=0;
        while(j!=c){
            for(int i=1;i<r;i++){
                if(strs[i][j]<strs[i-1][j]){
                    c1++;
                    break;
                }
            }
            j++;
        }
        return c1;
    }
};