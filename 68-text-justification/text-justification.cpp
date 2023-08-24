class Solution {
public:
    vector<int> calc(int minspace,int avail){
        vector<int>v;
        
        while(minspace>0 && avail>0){
            int val=ceil((float)avail/minspace);
            v.push_back(val);
            avail-=val;
            minspace--;
        }
        return v;
    }
    void tokenize(string const &str, const char* delim,vector<string> &out)
    {
        char *token = strtok(const_cast<char*>(str.c_str()), delim);
        while (token != nullptr)
        {
            out.push_back(string(token));
            token = strtok(nullptr, delim);
        }
    }
    void adjust(string &temp,int &maxWidth,int c){
        vector<string>str;
        tokenize(temp,"$",str);
        
        int minspaces=str.size()-1;
        string x="";
        if(str.size()==1){
            x+=str[0];
            for(int i=0;i<maxWidth-c;i++){
                x+=" ";
            }
            
        }
        else{
            vector<int>spaces=calc(str.size()-1,maxWidth-c);
            
            for(int i=0;i<spaces.size();i++){
                x+=str[i];
                for(int j=0;j<spaces[i];j++){
                    x+=" ";
                }
            }
            x+=str[str.size()-1];
        }
        temp=x;
        
    }
    void ret(vector<string>& words, int &maxWidth,int i,vector<string>&ans){
        
        if(i==words.size()){
            return;
        }
        int sum=0,c=0;
        string temp="";
        int j=i;
        for(j=i;j<words.size();j++){
            if(sum+words[j].length()<=maxWidth){
                c+=words[j].length();
                sum+=words[j].length();
                temp+=words[j];
                temp+="$";
            }
            else{
                break;
            }
            sum++;
        }
        int f=0;
        
        adjust(temp,maxWidth,c);
        
        ans.push_back(temp);
        ret(words,maxWidth,j,ans);
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>v;
        ret(words,maxWidth,0,v);
        string last=v.back();
        vector<string>val;
        tokenize(last," ",val);
        
        string temp="";
        for(int i=0;i<val.size();i++){
            if(i!=val.size()-1){
                temp+=val[i]+" ";
            }
            else{
                temp+=val[i];
            }
        }
        int x=temp.length();
        for(int i=0;i<(maxWidth-x);i++){
            
            temp+=" ";
        }
        v.back()=temp;
        return v;
    }
};