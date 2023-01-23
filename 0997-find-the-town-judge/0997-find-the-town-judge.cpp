class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>m1;
        
        for(int i=0;i<trust.size();i++){
            if(m1[trust[i][1]]!=10001){
                m1[trust[i][1]]++;
            }
            m1[trust[i][0]]=10001;
        }
        if(n==1){
            return 1;
        }
        for(auto it:m1){
            if(it.second==n-1){
                return it.first;
            }
        }
        return -1;
    }
    
};