class Solution {
public:
    vector<int> ret(string &exp,int l,int r){
        if(r-l<=1){
            if(r-l==0){
                return {exp[l]-'0'};
            }
            else{
                string temp="";
                temp+=exp[l];
                temp+=exp[l+1];
                return {stoi(temp)};
            }
        }
        vector<int>ans;
        for(int i=l;i<=r;i++){
            if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*'){
                vector<int>left=ret(exp,l,i-1);
                vector<int>right=ret(exp,i+1,r);
                if(exp[i]=='+'){
                    for(auto it:left){
                        for(auto it1:right){
                            ans.push_back(it+it1);
                        }
                    }
                }
                else{
                   if(exp[i]=='-'){
                        for(auto it:left){
                            for(auto it1:right){
                                ans.push_back(it-it1);
                            }
                        }
                    } 
                    else{
                        for(auto it:left){
                            for(auto it1:right){
                                ans.push_back(it*it1);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string exp) {
        
        vector<int>v=ret(exp,0,exp.length()-1);
        if(v.empty()){
            return {stoi(exp)};
        }
        return v;
    }
};