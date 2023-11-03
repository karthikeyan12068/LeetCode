class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int>s1,s2;
        int z=0;
        vector<string>ans;
        for(int i=1;i<=n;i++){
            if(target[z]==i){
                if(s2.empty()){
                   ans.push_back("Push");
                   s1.push(i); 
                }
                else{
                    while(!s2.empty()){
                        s2.pop();
                        ans.push_back("Pop");
                    }
                    ans.push_back("Push");
                    s1.push(i); 
                }
                z++;
            }
            else{
                s2.push(i);
                ans.push_back("Push");
            }
            if(z==target.size()){
                break;
            }
        }
        return ans;
    }
};