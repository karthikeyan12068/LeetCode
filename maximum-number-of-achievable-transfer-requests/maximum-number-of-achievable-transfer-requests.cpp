class Solution {
public:
    bool ret(vector<vector<int>>& requests,vector<int>&deg,int i,int tar){
        if(tar<0){
            return false;
        }
        if(i==requests.size()){
            for(int i=0;i<deg.size();i++){
                if(deg[i]!=0){
                    return false;
                }
            }
            return true;
        }
        deg[requests[i][0]]--;
        deg[requests[i][1]]++;
        bool pick=ret(requests,deg,i+1,tar);
        deg[requests[i][0]]++;
        deg[requests[i][1]]--;
        bool npick=ret(requests,deg,i+1,tar-1);
        return pick|npick;
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        for(int i=requests.size()-1;i>=0;i--){
            vector<int>deg(n,0);
            if(ret(requests,deg,0,requests.size()-(i+1))){
                return i+1;
            }
        }
        return 0;
    }
};