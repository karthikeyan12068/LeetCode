class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        map<int,int>m;
        for(int i=0;i<s.length();i++){
            if(s[i]==')' || s[i]=='('){
                if(s[i]==')'){
                    if(st.empty()){
                        m[i]++;
                    }else{
                        st.pop();
                    }
                }else{
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            m[st.top()]++;
            st.pop();
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(m[i]==0){
                ans+=s[i];
            }
        }
        return ans;
    }
};