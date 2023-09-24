class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<long double>>dp(100,vector<long double>(100,0.0));
        long double x=(long double)poured;
        dp[0][0]=x;
        cout << std::fixed << dp[0][0] << std::endl;
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                long double extra=dp[i][j]-1.0;
                
                if(extra>0.0){
                    
                    if(i+1<100){
                        
                        dp[i+1][j]+=(extra*0.5);
                        dp[i+1][j+1]+=(extra*0.5);
                    }
                }
            }
        }
        if(dp[query_row][query_glass]!=0.0){
            if(dp[query_row][query_glass]<1.0){
                return dp[query_row][query_glass];
            }
            return (double)1.0;
        }
        return (double)0.0;
        
    }
};