class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        string temp="";
        for(int i=0;i<num.length();i++){
            temp+=num[i];
            if((num[i]-'0')%2!=0){
                ans=temp;
            }
        }
        return ans;
    }
};