class Solution {
public:
    int totalMoney(int n) {
        unordered_map<int,int>m;
        for(int i=0;i<=6;i++){
            m[i]=i+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=m[i%7];
            m[i%7]++;
        }
        return ans;
    }
};