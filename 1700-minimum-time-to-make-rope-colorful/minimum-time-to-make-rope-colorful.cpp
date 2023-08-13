class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
       int ans=0;
       for(int i=0;i<colors.length();i++){
           multiset<int>s;
           int j;
           s.insert(neededTime[i]);
           for(j=i+1;j<colors.length();j++){
               if(colors[j]==colors[j-1]){
                   s.insert(neededTime[j]);
               }
               else{
                   break;
               }
           }
           i=j-1;
           int x=s.size()-1;
           for(auto it:s){
               if(x>0){
                ans+=it;
                x--;
               }
               else{
                   break;
               }
           }
       } 
       return ans;
    }
};