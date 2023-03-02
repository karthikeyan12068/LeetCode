class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        for(int i=0;i<chars.size()-1;i++){
            int c=1,j;
            for(j=i+1;j<chars.size();j++){
                if(chars[i]==chars[j]){
                    c++;
                }
                else{
                    break;
                }
            }
            j--;
            i=j;
            if(c!=1){
                s+=chars[i]+to_string(c);
            }
            else{
                s+=chars[i];
            }
        }
        if(chars.size()>=2){
            if(chars[chars.size()-1]!=chars[chars.size()-2]){
                s+=chars[chars.size()-1];
            }
        }
        else{
            return chars.size();
        }
        vector<char>ans;
        for(auto it:s){
            ans.push_back(it);
        }
        chars=ans;
        return s.length();
    }
};