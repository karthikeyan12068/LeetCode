class Solution {
public:
    string ret(string &s){
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]!='#'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string ans1="";
        while(!st.empty()){
            ans1+=st.top();
            st.pop();
        }
        return ans1;
    }
    bool backspaceCompare(string s, string t) {
        string ans1=ret(s),ans2=ret(t);
        return ans1==ans2;
    }
};