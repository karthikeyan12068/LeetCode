class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>m1,m2;
        for(auto it:s1){
            m1[it]++;
        }
        
        string a="";
        for(int i=0;i<s2.length();i++){
            a=s2[i]+a;
            m2[s2[i]]++;
            if(m1[s2[i]]==0){
                m1[s2[i]]=0;
            }
            if(a.length()==s1.length()){
                if(m1==m2){
                    return true;
                }
                /*for(auto it:m2){
                    cout<<it.first<<" "<<it.second<<"\n";
                }*/
                m2[a.back()]--;
                a.pop_back();
            }
        }
        return false;
    }
};