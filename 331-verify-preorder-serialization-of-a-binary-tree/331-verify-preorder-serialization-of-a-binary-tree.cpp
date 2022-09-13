class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<pair<string,int>>stack;
        int st=0;
        string g="";
        string s=preorder;
        while(!s.empty()){
            if(s.front()!=','){
                g+=s.front();
            }
            else{
                if(!stack.empty()){
                    stack.top().second++;
                    if(stack.top().second==2){
                        stack.pop();
                    }
                }
                if(g!="#"){
                    stack.push({g,0});
                }
                else{
                    if(stack.empty()){
                        return false;
                    }
                }
                g="";
            }
            s.erase(0,1);
        }
        if(!stack.empty()){
            stack.top().second++;
            if(stack.top().second==2){
                stack.pop();
            }
        }
        if(g!="#"){
            stack.push({g,0});
        }
        if(stack.empty() && s.empty()){
            return true;
        }
        cout<<stack.top().first<<" "<<stack.top().second;
        return false;
    }
};