class Solution {
public:
    int maxScore(string s) {
        vector<int>v1(s.length()),v2(s.length());
        for(int i=0;i<s.length();i++){
            if(i==0){
                if(s[i]=='0'){
                    v1[i]=1;
                }
            }
            else{
                if(s[i]=='0'){
                    v1[i]=v1[i-1]+1;
                }
                else{
                    v1[i]=v1[i-1];
                }
            }
        }
        for(int i=s.length()-1;i>=0;i--){
            if(i==s.length()-1){
                if(s[i]=='1'){
                    v2[i]=1;
                }
            }
            else{
                if(s[i]=='1'){
                    v2[i]=v2[i+1]+1;
                }
                else{
                    v2[i]=v2[i+1];
                }
            }
        }
        int c=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                c=max(c,v1[i]+v2[i]);
            }
            else{
                c=max(c,v1[i]+(v2[i]-1));
            }
        }
        return  c;
    }
};