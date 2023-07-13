class Solution {
public:
    void ret(vector<string>&v,int &n,int i,int o,string temp){
        if(i==n){
            if(o==0){
                v.push_back(temp);
            }
            return;
        }
        if(o!=0){
            ret(v,n,i+1,o-1,temp+')');
        }
        ret(v,n,i+1,o+1,temp+'(');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        n*=2;
        ret(v,n,0,0,"");
        return v;
    }
};