class Solution {
public:
    int minDeletions(string s) {
        map<char,int>m1;
        for(auto it:s){
            m1[it]++;
        }
        map<int,int>m2;
        int max1=-1;
        for(auto it:m1){
            m2[it.second]++;
            max1=max(max1,it.second);
        }
        map<int,int>m3;
        for(int i=0;i<max1;i++){
            if(m2[i]==0){
                m3[i]++;
            }
        }
        int ans=0;
        
        for(auto it:m2){
            int x=it.second;
            while(x>1){
                auto it1=m3.lower_bound(it.first);
                if(it1!=m3.end()){
                    it1--;
                    ans+=(it.first-it1->first);
                    if(it1->first!=0){
                        m3.erase(it1);
                    }
                }
                else{
                    it1--;
                    ans+=(it.first-it1->first);
                    if(it1->first!=0){
                        m3.erase(it1);
                    }
                }
                x--;
            }
        }
        return ans;
    }
};