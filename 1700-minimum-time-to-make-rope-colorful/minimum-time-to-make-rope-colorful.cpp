class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0,j=1;
        int ans=0;
        while(j<colors.length()){
            priority_queue<int,vector<int>,greater<>>s;
            s.push(neededTime[i]);
            if(colors[i]==colors[j]){
                while(j<colors.length() && colors[i]==colors[j]){
                    s.push(neededTime[j]);
                    j++;
                }
            }
            while(s.size()>1){
                ans+=s.top();
                s.pop();
            }
            i=j;
            j++;
        }
        return ans;
    }
};