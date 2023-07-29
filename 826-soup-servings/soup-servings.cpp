class Solution {
public:
    
    double totposeve(int n1,int n2,vector<vector<double>>&dp){
        if(n1<=0 && n2<=0){
            return 0.5;
        }
        if(n1<=0){
            return 1.0;
        }
        if(n1>0 && n2<=0){
            return 0.0;
        }    
        if(n1>=0 && n2>=0 && dp[n1][n2]!=-1.0){
            return dp[n1][n2];
        }
        double val1=0.25*totposeve(n1-100,n2,dp);
        double val2=0.25*totposeve(n1-75,n2-25,dp);
        double val3=0.25*totposeve(n1-50,n2-50,dp);
        double val4=0.25*totposeve(n1-25,n2-75,dp);
        return dp[n1][n2]=val1+val2+val3+val4;
    }
    double soupServings(int n) {
        if(n>=5000){
            return 1.00000;
        }
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));
        return totposeve(n,n,dp);

    }
};