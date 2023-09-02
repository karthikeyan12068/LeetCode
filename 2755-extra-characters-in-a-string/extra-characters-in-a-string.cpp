class Solution {
public:
    map<pair<string,int>,int>dp;
    int ret(string &s,string temp,int i,map<string,int>&m){
        
        if(i==s.length()){
            if(temp.length()==0 || m[temp]==1){
                return 0;
            }
            return temp.length();
        }
        if(dp.find({temp,i})!=dp.end()){
            return dp[{temp,i}];
        }
        int brak=0,nbrak=0;
        string x="";
        x+=s[i];
        if(m[temp]!=0){
            brak=0+ret(s,x,i+1,m);
        }
        else{
            brak=temp.length()+ret(s,x,i+1,m);
        }
        nbrak=0+ret(s,temp+s[i],i+1,m);
        return  dp[{temp,i}]=min(brak,nbrak);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        map<string,int>m;
        for(auto it:dictionary){
            m[it]++;
        }
        
        return ret(s,"",0,m);
    }
};