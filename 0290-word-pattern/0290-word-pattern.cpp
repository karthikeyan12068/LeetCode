class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string>m1;
        map<string,int>m2;
        istringstream ss(s);
        string del;
        int i=0;
        while(getline(ss, del, ' ')) {
            if(i>=pattern.length()){
                return false;
            }
            if(m1[pattern[i]]==""){
                if(m2[del]!=0){
                    return false;
                }
                m1[pattern[i]]=del;
                m2[del]++;
            }
            else{
                if(m1[pattern[i]]!=del){
                    return false;
                }
            }
            i++;
        }
        if(i!=pattern.length()){
            return false;
        }
        return true;
    }
};