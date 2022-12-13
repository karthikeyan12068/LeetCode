class Solution {
public:
    bool pali(string S)
    {
        
        for (int i = 0; i < S.length() / 2; i++) {

            if (S[i] != S[S.length() - i - 1]) {
                
                return false;
            }
        }
        
        return true;
    }
    void ret(string s,int i,vector<string>v,vector<vector<string>>&ans,string z){
        if(i>=s.length()){
            if(z==s){
                ans.push_back(v);
            }
            return;
        }
        string temp="";
        for(int i1=i;i1<s.length();i1++){
            temp+=s[i1];
            if(pali(temp)){
                v.push_back(temp);
                string bef=z;
                z+=temp;
                ret(s,i1+1,v,ans,z);
                if(!v.empty()){
                    v.pop_back();
                }
                z=bef;
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>v1;
        vector<string>v;
        string z="";
        ret(s,0,v,v1,z);
        return v1;
    }
};