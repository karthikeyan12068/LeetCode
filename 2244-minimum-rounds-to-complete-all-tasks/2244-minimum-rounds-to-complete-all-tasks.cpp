class Solution {
public:
    
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m1;
        for(int i=0;i<tasks.size();i++){
            m1[tasks[i]]++;
        }
        int c=0;
        for(auto it:m1){
            int n=it.second;
           if(it.second!=1){
               if(it.second==2){
                   c++;
               }
               else{
                   if(n%3!=0){
                       while(n%3!=0){
                           n-=2;
                           c++;
                       }
                       c+=n/3;
                   }
                   else{
                       c+=n/3;
                   }
               }
           }
            else{
                return -1;
            }
        }
        return c;
    }
};