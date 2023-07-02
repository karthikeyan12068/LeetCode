class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>m1;
        m1['I']=1;
        m1['V']=5;
        m1['X']=10;
        m1['L']=50;
        m1['C']=100;
        m1['D']=500;
        m1['M']=1000;
        stack<char>st;
        for(auto it:s){
            st.push(it);
        }
        int sum=0;
        char bef='$';
        while(!st.empty()){
            if(bef=='$'){
                bef=st.top();
                st.pop();
                sum+=m1[bef];
            }
            else{
                if((bef=='V' || bef=='X') && st.top()=='I'){
                    sum--;
                }
                else{
                    if((bef=='L' || bef=='C') && st.top()=='X'){
                        sum-=10;
                    }
                    else{
                        if((bef=='D' || bef=='M') && st.top()=='C'){
                            sum-=100;
                        }
                        else{
                            sum+=m1[st.top()];
                        }
                    }
                }
                bef=st.top();
                st.pop();
            }
        }
        return sum;
    }
};