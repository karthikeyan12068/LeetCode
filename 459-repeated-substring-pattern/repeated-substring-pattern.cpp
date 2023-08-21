class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        
        if(s.length()==1){
            return false;
        }
        if(count(s.begin(),s.end(),s[0])==s.length()){
            return true;
        }
        if(s.length()==2){
            if(s[0]==s[1]){
                return true;
            }
            return false;
        }
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                int i1=i;
                int i2=n/i;
                string t1="",t2="";
                
                for(int j=0;j<s.length();j++){
                    if(j+1<=i1){
                        t1+=s[j];
                    }
                    else{
                        t2+=s[j];
                        if((j+1)%i1==0){
                            if(t1!=t2){
                                break;
                            }
                            else{
                                t2="";
                            }
                        }
                    }
                }
                if(t2.empty()){
                    return true;
                }
                else{
                    t1="",t2="";
                    for(int j=0;j<s.length();j++){
                        if(j+1<=i2){
                            t1+=s[j];
                        }
                        else{
                            t2+=s[j];
                            if((j+1)%i2==0){
                                if(t1!=t2){
                                    break;
                                }
                                else{
                                    t2="";
                                }
                            }
                        }
                    }
                    if(t2.empty()){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};