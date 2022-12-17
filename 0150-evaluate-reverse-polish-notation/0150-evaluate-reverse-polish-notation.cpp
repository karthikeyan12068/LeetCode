class Solution {
public:
    long long str_to_in(string s)
    {
        stringstream geek(s);
        long long x = 0;
        geek >> x;
        return x;
    }
    long long evalRPN(vector<string>& tokens) {
        stack<long long>s1;
        for(auto it:tokens){
            if(it!="+" && it!="-" && it!="*" && it!="/"){
                long long z=str_to_in(it);
                s1.push(z);
            }
            else{
                long long val1=s1.top();
                s1.pop();
                long long val2=s1.top();
                s1.pop();
                swap(val1,val2);
                if(it=="+"){
                    s1.push(val1+val2);
                }
                if(it=="-"){
                    s1.push(val1-val2);
                }
                if(it=="*"){
                    s1.push(val1*val2);
                }
                if(it=="/"){
                    s1.push(val1/val2);
                }
            }
        }
        return s1.top();
    }
};