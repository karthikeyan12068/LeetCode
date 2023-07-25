class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        for(int i=0;i<num.length();i++){
            while(!s.empty() && s.top()>num[i] && k>0){
                k--;
                s.pop();
            }
            s.push(num[i]);
        }
        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }
        if(s.empty()){
            return "0";
        }
        string temp="";
        while(!s.empty()){
            temp+=s.top();
            s.pop();
        }
        while(!temp.empty() && temp.back()=='0'){
            temp.pop_back();
        }
        if(temp.empty()){
            return "0";
        }
        reverse(temp.begin(),temp.end());

        return temp;
    }
};