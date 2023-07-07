class Solution {
public:
    int ret(string s, int k,char c){
        int ans=0;
        int l=0,r=0;
        
        while(true){
            while(r<s.length() && k>0){
                if(s[r]!=c){
                    r++;
                }
                else{
                    
                    r++;
                    k--;
                }
            }
            if(r<s.length() && s[r]!=c){
                while(r<s.length() && s[r]!=c){
                    r++;
                }
            }
            ans=max(ans,r-l);
            while(l<=r){
                if(s[l]==c){
                    l++;
                    k++;
                    break;
                }
                else{
                    l++;
                }
            }
            if(r>=s.length()){
                break;
            }
        }
        return ans;
    }
    int maxConsecutiveAnswers(string s, int k) {
        return max(ret(s,k,'T'),ret(s,k,'F'));
    }
};