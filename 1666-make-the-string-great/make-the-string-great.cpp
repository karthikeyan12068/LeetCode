class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto it:s){
            if(st.empty()){
                st.push(it);
            }else{
                if(it==st.top()){
                    st.push(it);
                    continue;
                }
                if(tolower(st.top())==tolower(it)){
                    st.pop();
                }else{
                    st.push(it);
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};