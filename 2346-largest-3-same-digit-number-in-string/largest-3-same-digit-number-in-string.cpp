class Solution {
public:
    string largestGoodInteger(string num) {
        string temp="";
        for(int i=0;i<num.length()-2;i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                if(temp.empty()){
                    temp+=num[i];
                    temp+=num[i+1];
                    temp+=num[i+2];
                }
                else{
                    string temp1="";
                    temp1+=num[i];
                    temp1+=num[i+1];
                    temp1+=num[i+2];
                    temp=max(temp,temp1);
                }
            }
        }
        return temp;
    }
};