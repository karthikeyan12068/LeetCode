class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int>m;
        vector<int>vis(27);
        for(auto it:s){
            m[it]++;
        }
        stack<char>s1;
        
        for(auto it:s){
            if(vis[it-'a']==0){
                while(!s1.empty() && s1.top()>it && m[s1.top()]!=0){
                    vis[s1.top()-'a']=0;
                    s1.pop();
                }
                m[it]--;
                if(vis[it-'a']==0){
                    s1.push(it);
                    vis[it-'a']=1;
                }
            }
            else{
                m[it]--;
            }
        }
        string ans="";
        while(!s1.empty()){
            ans+=s1.top();
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};