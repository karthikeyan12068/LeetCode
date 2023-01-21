class Solution {
public:
    int str_to_in(string s)
    {
        stringstream geek(s);
        int x = 0;
        geek >> x;
        return x;
    }

    void ret(string s,string temp,int i,int c,vector<string>&ans){
        if(i==s.length() || c==4){
            if(c==4){
                temp.pop_back();
            }
            if(temp.length()==s.length()+3){
                string t="";
                for(int i=0;i<temp.length();i++){
                    if(temp[i]=='.' || i==temp.length()-1){
                        if(temp[i]!='.' && i==temp.length()-1){
                            t+=temp[i];
                        }
                        if(t.empty()){
                            return;
                        }
                        /*if(t[0]=='0'){
                            return;
                        }*/
                        int chk=str_to_in(t);
                        if(to_string(chk).length()==t.length() && chk>=0 && chk<=255){
                            t="";
                        }
                        else{
                            return;
                        }
                    }
                    else{
                        t+=temp[i];
                        if(t.length()>=4){
                            return;
                        }
                    }
                }
                ans.push_back(temp);
                return;
            }
            return;
        }
        ret(s,temp+".",i,c+1,ans);
        ret(s,temp+s[i],i+1,c,ans);
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>v;
        ret(s,"",0,0,v);
        return v;
    }
};