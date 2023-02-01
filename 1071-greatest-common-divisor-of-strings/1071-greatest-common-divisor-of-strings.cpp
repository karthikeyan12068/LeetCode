class Solution {
public:
    string ret(string chk,string str1,string str2){
        string c=chk;
        int f=0;
        while(chk.length()<=str1.length()){
            if(chk.length()==str2.length() && chk!=str2 || chk.length()>str1.length() && f==0){
                return "";  
            }
            else{
               if(chk.length()==str2.length() && chk==str2){
                   f=1;
               } 
            }
            if(chk.length()==str1.length() && chk!=str1 || chk.length()>=str1.length() && f==0){
                return "";
            }
            else{
                if(chk.length()==str1.length() && chk==str1){
                    f=2;
                    break;
                }
            }
            chk+=c;
        }
        if(f!=2){
            return "";
        }
        return c;
    }
    string gcdOfStrings(string str1, string str2) {
        string temp="";
        if(str1.length()<str2.length()){
            swap(str1,str2);
        }
        for(int i=0;i<str2.length();i++){
            if(str2[i]!=str1[i]){
                return "";
            }
        }
        string ans="";
        for(int i=0;i<str2.length();i++){
            temp+=str2[i];
            string z=ret(temp,str1,str2);
            ans=(z.length()>ans.length())?z:ans;
        }
        return ans;
    }
};