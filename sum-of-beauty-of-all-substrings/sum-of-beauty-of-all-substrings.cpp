class Solution {
public:
    int beautySum(string s) {
        int x=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int>m1;
            m1[s[i]]++;
            for(int j=i+1;j<s.length();j++){
                m1[s[j]]++;
                int min1=INT_MAX,max1=INT_MIN;
                for(auto it:m1){
                    min1=min(min1,it.second);
                    max1=max(max1,it.second);
                }
                x+=max1-min1;
            }
        }
        return x;
    }
};