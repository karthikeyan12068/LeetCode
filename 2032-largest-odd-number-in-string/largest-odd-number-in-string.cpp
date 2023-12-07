class Solution {
public:
    string largestOddNumber(string num) {
        int ind=-1;
        for(int i=num.length()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                ind=i;
                break;
            }
        }
        string temp="";
        if(ind==-1){
            return temp;
        }
        for(int i=0;i<=ind;i++){
            temp+=num[i];
        }
        return temp;
    }
};