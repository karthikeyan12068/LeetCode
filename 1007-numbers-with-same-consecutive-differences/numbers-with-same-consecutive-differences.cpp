class Solution {
public:
    void ret(int n,int k,string temp,set<int>&ans){
        if(n==0){
            ans.insert(stoi(temp));
            return;
        }
        if(temp.empty()){
            for(int i=1;i<=9;i++){
                ret(n-1,k,temp+to_string(i),ans);
            }
        }
        else{
            int prev=temp.back()-'0';
            if(prev-k>=0 && prev+k<=9){
                ret(n-1,k,temp+to_string(prev-k),ans);
                ret(n-1,k,temp+to_string(prev+k),ans);
            }
            else{
                if(prev-k>=0){
                    ret(n-1,k,temp+to_string(prev-k),ans);
                }
                else{
                    if(prev+k<=9){
                        ret(n-1,k,temp+to_string(prev+k),ans);
                    }
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int>ans;
        ret(n,k,"",ans);
        vector<int>v;
        for(auto it:ans){
            v.push_back(it);
        }
        return v;
    }
};