class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int x1=count(s.begin(),s.end(),'1')-s.length();
        int x2=count(s.begin(),s.end(),'0')-s.length();
        int ans=min(abs(x1),abs(x2));
        if(ans!=0){
            vector<pair<int,int>>v(s.length());
            for(int i=s.length()-1;i>=0;i--){
                if(i!=s.length()-1){
                    v[i]={v[i+1].first,v[i+1].second};
                }
                if(s[i]=='0'){
                    v[i].first++;
                }
                else{
                    v[i].second++;
                }
            }
            int rem=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='1'){
                    ans=min(ans,v[i].first+rem);
                    rem++;
                }
            }
        }
        return ans;
    }
};