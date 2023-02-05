class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>m1,m2;
        char a='a';
        for(int i=0;i<26;i++){
            m1[a]=0;
            m2[a]=0;
            a++;
        }
        for(auto it:p){
            m1[it]++;
        }
        string z="";
        vector<int>v;
        for(int i=0;i<s.length();i++){
            z=s[i]+z;
            m2[s[i]]++;
            if(z.length()==p.length()){
                if(m1==m2){
                    v.push_back(i+1-p.length());
                }
                m2[z.back()]--;
                z.pop_back();
            }
        }
        return v;
    }
};