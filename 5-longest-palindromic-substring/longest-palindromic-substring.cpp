class Solution {
public:
    string longestPalindrome(string s) {
        int ans=0;
        string an="";
       for(int i=0;i<s.length();i++){
           int lp=i,rp=i;
           int len=0;
           string temp="";
           while(lp>=0 && rp<s.length() && s[lp]==s[rp]){
               if(s[lp]==s[rp]){
                   if(lp==rp){
                       temp+=s[lp];
                   }
                   else{
                       temp+=s[rp];
                       temp=s[lp]+temp;
                   }
                   len=(rp-lp)+1;
                   lp--;
                   rp++;
               }
           }
           if(ans<len){
               ans=max(ans,len);
               an=temp;
           }
           temp="";
           len=0;
           lp=i,rp=i+1;
           while(lp>=0 && rp<s.length() && s[lp]==s[rp]){
               if(s[lp]==s[rp]){
                   temp+=s[rp];
                   temp=s[lp]+temp;
                   len=(rp-lp)+1;
                   lp--;
                   rp++;
               }
           }
           if(ans<len){
               ans=max(ans,len);
               an=temp;
           }
       }
       return an; 
    }
};