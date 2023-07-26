class Solution {
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),1));
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            for(int j=matrix[0].size()-1;j>=0;j--){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }
                else{
                    if(j+1<c){
                        if(matrix[i][j+1]!='0'){
                            dp[i][j]+=dp[i][j+1];
                        }
                    }
                }
            }
        }
        int max1=0;
        for(int i=0;i<c;i++){
            stack<int>s;
            vector<int>rmin(r,r);
            for(int j=0;j<r;j++){
                while(!s.empty() && dp[s.top()][i]>dp[j][i]){
                    rmin[s.top()]=j;
                    s.pop();
                }
                s.push(j);
            }
            while(!s.empty()){
                s.pop();
            }
            vector<int>lmin(r,-1);
            for(int j=r-1;j>=0;j--){
                while(!s.empty() && dp[s.top()][i]>dp[j][i]){
                    lmin[s.top()]=j;
                    s.pop();
                }
                s.push(j);
            }
            for(int j=0;j<r;j++){
                int val=(rmin[j]-j)+(j-lmin[j]);
                val--;
                max1=max(max1,dp[j][i]*val);
            }
        }
        
        dp.clear();
        dp.resize(matrix.size(),vector<int>(matrix[0].size(),1));
        for(int i=0;i<c;i++){
            for(int j=r-1;j>=0;j--){
                if(matrix[j][i]=='0'){
                    dp[j][i]=0;
                }
                else{
                    if(j+1<r && matrix[j+1][i]!='0'){
                        dp[j][i]+=dp[j+1][i];
                    }
                }
            }
        }
        for(int i=0;i<r;i++){
            stack<int>s;
            vector<int>rmin(c,c);
            for(int j=0;j<c;j++){
                while(!s.empty() && dp[i][s.top()]>dp[i][j]){
                    rmin[s.top()]=j;
                    s.pop();
                }
                s.push(j);
            }
            while(!s.empty()){
                s.pop();
            }
            vector<int>lmin(c,-1);
            for(int j=c-1;j>=0;j--){
                while(!s.empty() && dp[i][s.top()]>dp[i][j]){
                    lmin[s.top()]=j;
                    s.pop();
                }
                s.push(j);
            }
            for(int j=0;j<c;j++){
                int val=(lmin[j]-j)+(j-lmin[j]);
                val--;
                max1=max(max1,dp[i][j]*val);
            }
        }
        return max1;
    }
};