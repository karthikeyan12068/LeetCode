class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        if(s!=goal){
            int i1=-1,i2=-1;
            for(int i=0;i<s.length();i++){
                if(s[i]!=goal[i]){
                    if(i1==-1){
                        i1=i;
                    }
                    else{
                        if(i2==-1){
                            i2=i;
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
            if(i1==-1 || i2==-1){
                return false;
            }
            swap(s[i1],s[i2]);
            if(s==goal){
                return true;
            }
            return false;
        }
        else{
            unordered_map<char,int>m1;
            for(auto it:s){
                m1[it]++;
                if(m1[it]>1){
                    return true;
                }
            }
        }
        return false;
    }
};