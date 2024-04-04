class Solution {
public:
    int lengthOfLastWord(string s) {
        while(s.back()==' '){
            s.pop_back();
        }
        string ans="";
        reverse(s.begin(),s.end());
        for(auto it:s){
            if(it==' '){
                break;
            }else{
                ans+=it;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans.length();
    }
};