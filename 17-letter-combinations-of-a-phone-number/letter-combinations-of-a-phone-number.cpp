class Solution {
public:
    void ret(vector<string>&left,vector<string>&v){
        vector<string>a;
        /*for(auto it:left){
            cout<<it<<' ';
        }
        cout<<'\n';*/
        int x=left.size();
        for(int i=0;i<x;i++){
            for(auto it:v){
                a.push_back(left[i]+it);
            }
        }
        left=a;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<string>>m;
        m['2']={"a","b","c"};
        m['3']={"d","e","f"};
        m['4']={"g","h","i"};
        m['5']={"j","k","l"};
        m['6']={"m","n","o"};
        m['7']={"p","q","r","s"};
        m['8']={"t","u","v"};
        m['9']={"w","x","y","z"};
        vector<string>ans;
        for(int i=0;i<digits.size();i++){
            if(i==0){
                ans=m[digits[i]];
            }
            else{
                ret(ans,m[digits[i]]);
            }
        }
        return ans;
    }
};