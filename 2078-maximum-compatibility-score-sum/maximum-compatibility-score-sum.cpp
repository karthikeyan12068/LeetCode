class Solution {
public:
    int n;
    int dp[9][1<<9];
    int ret(vector<vector<int>>& students, vector<vector<int>>& mentors,int i,int x){
        int ans=0;
        if(dp[i][x]!=-1){
            return dp[i][x];
        }
        for(int j=0;j<n;j++){
            if(((x>>(j+1))&1)==0){
                int match=0;
                for(int k=0;k<mentors[i].size();k++){
                    if(mentors[i][k]==students[j][k]){
                        match++;
                    }
                }
                ans=max(ans,match+ret(students,mentors,i+1,x^(1<<(j+1))));
            }
        }
        return dp[i][x]=ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n=students.size();
        memset(dp,-1,sizeof(dp));
        return ret(students,mentors,0,0);
    }
};