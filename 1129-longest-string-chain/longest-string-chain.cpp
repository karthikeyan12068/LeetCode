class Solution {
public:
    int dp[1001][1002];
    int ret(vector<string>& words,int cur,int prev){
        if(cur==words.size()){
           
            return 0;
        }
        if(dp[cur][prev+1]!=-1){
            return dp[cur][prev+1];
        }
        int take=0,ntake=0;
        ntake=0+ret(words,cur+1,prev);
        if(prev==-1){
            take=1+ret(words,cur+1,cur);
        }
        else{
            if(words[prev].length()+1==words[cur].length()){
                int j=0,f=0;
                for(int i=0;i<words[cur].length();i++){
                    if(words[cur][i]==words[prev][j]){
                        j++;
                    }
                    else{
                        if(f==0){
                            f=1;
                        }
                        else{
                            f=2;
                            break;
                        }
                    }
                }
                if(f==1){
                    take=1+ret(words,cur+1,cur);
                }
            }
        }
        return dp[cur][prev+1]=max(take,ntake);
    }
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,string>>v;
        for(int i=0;i<words.size();i++){
            v.push_back({words[i].length(),words[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<words.size();i++){
            words[i]=v[i].second;
        }
        return ret(words,0,-1);
    }
};