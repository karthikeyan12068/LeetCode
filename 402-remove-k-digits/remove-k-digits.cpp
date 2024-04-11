class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char>s;
        for(auto it:num){
            while(!s.empty() && s.top()>it && k>0){
                k--;
                s.pop();
            }
            s.push(it);
            //cout<<it<<'\n';
        }
        
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        
        while(ans.length()>0 && k--){
            ans.pop_back();
        }
        /*while(ans.length()>0 && ans.back()=='0'){
            ans.pop_back();
        }*/
        if(ans.length()>0){
            if(ans[0]=='0'){
                reverse(ans.begin(),ans.end());
                while(ans.length()>0 && ans.back()=='0'){
                    ans.pop_back();
                }
                reverse(ans.begin(),ans.end());
            }
        }
        return (ans.length()==0)?"0":ans;
    }
};