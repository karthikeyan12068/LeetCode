class Solution {
public:
    string ret(string chk,string str1,string str2){
        string c=chk;
        while(chk.length()<=str1.length()){
            if(chk.length()==str2.length() && chk!=str2){
                return "";  
            }
            if(chk.length()==str1.length() && chk!=str1){
                return "";
            }
            chk+=c;
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
        for(int i=1;i<=sqrt(str1.length());i++){
            if(str1.length()%i==0){
                if(str2.length()%i==0){
                    string z=ret(temp+str2.substr(0,i),str1,str2);
                    ans=(ans.length()<z.length())?z:ans;
                }
                if((str2.length()%(str1.length()/i))==0){
                    string z=ret(temp+str2.substr(0,(str1.length()/i)),str1,str2);
                    ans=(ans.length()<z.length())?z:ans;
                }
            }
        }
        return ans;
    }
};