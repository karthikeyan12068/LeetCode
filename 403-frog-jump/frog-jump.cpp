class Solution {
public:
    int dp[2002][2002];
    long long int ret(vector<int>& stones,long long int ind,long long int prev){
        if(ind==stones.size()-1){
            return true;
        }
        if(dp[ind][prev+1]!=-1){
            if(dp[ind][prev+1]==0){
                return false;
            }
            return true;
        }
        bool ans=false;
        if(prev!=-1){
            long long int kx=(stones[ind]-stones[prev])-1;
            long long int ky=(stones[ind]-stones[prev]);
            long long int kz=(stones[ind]-stones[prev])+1;
            if(kx!=0){
                auto it=lower_bound(stones.begin()+ind+1,stones.end(),stones[ind]+kx);
                if(it!=stones.end()){
                    long long int nxt=it-stones.begin();
                    if(stones[nxt]==stones[ind]+kx){
                        ans=ans|ret(stones,nxt,ind);
                    }
                }
            }
            if(ky!=0){
                auto it=lower_bound(stones.begin()+ind+1,stones.end(),stones[ind]+ky);
                if(it!=stones.end()){
                    long long int nxt=it-stones.begin();
                    if(stones[nxt]==stones[ind]+ky){
                        ans=ans|ret(stones,nxt,ind);
                    }
                }
            }
            if(kz!=0){
                auto it=lower_bound(stones.begin()+ind+1,stones.end(),stones[ind]+kz);
                if(it!=stones.end()){
                    long long int nxt=it-stones.begin();
                    if(stones[nxt]==stones[ind]+kz){
                        ans=ans|ret(stones,nxt,ind);
                    }
                }
            }
        }
        else{
            long long int kx=ind+1;
            if(kx!=0){
                auto it=lower_bound(stones.begin()+ind+1,stones.end(),stones[ind]+kx);
                if(it!=stones.end()){
                    long long int nxt=it-stones.begin();
                    if(stones[nxt]==stones[ind]+kx){
                        ans=ans|ret(stones,nxt,ind);
                    }
                }
            }
        }
        if(ans==true){
            dp[ind][prev+1]=1;
        }
        else{
            dp[ind][prev+1]=0;
        }
        return ans;
    }
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return ret(stones,0,-1);
    }
};