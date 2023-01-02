class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        if(word.length()==1){
            return true;
        }
        if(toupper(word[0])==word[0]){
            int c=0;
            for(int i=1;i<word.length();i++){
                if(toupper(word[i])==word[i]){
                    c++;
                }
                else{
                    c--;
                }
            }
            if((n-1)==abs(c)){
                return true;
            }
        }
        else{
            int c=0;
            for(int i=1;i<word.length();i++){
                if(tolower(word[i])==word[i]){
                    c++;
                }
            }
            if(c==word.length()-1){
                return true;
            }
        }
        return false;
    }
};