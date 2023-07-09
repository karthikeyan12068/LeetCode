class Solution {
public:
    int ret(string s, int k,char c){
        int ans=0;
        int l=0,r=0;
        while(r<s.length()){
            if(s[r]==c){
                r++;
            }
            else{
                if(k!=0){
                    k--;
                    r++;
                }
                else{
                    if(s[l]!=c){
                        k++;
                    }
                    l++;
                }
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int ans=0;
        for(char i='A';i<='Z';i++){
            ans=max(ans,ret(s,k,i));
        }
        return ans;
    }
};