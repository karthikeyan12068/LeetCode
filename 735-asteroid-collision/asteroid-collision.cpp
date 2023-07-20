class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(int i=0;i<asteroids.size();i++){
            if(s.empty()){
                s.push(asteroids[i]);
            }
            else{
                if(s.top()>0 && asteroids[i]>0 || s.top()<0 && asteroids[i]<0 || s.top()<0 && asteroids[i]>0){
                    s.push(asteroids[i]);
                }
                else{
                    int ans=asteroids[i];
                    while(!s.empty() && s.top()>0 && ans<0){
                        int x=s.top();
                        s.pop();
                        if(abs(x)==abs(ans)){
                            ans=INT_MAX;
                            break;
                        }
                        else{
                            if(abs(asteroids[i])>abs(x)){
                                ans=asteroids[i];
                            }
                            else{
                                s.push(x);
                                ans=INT_MAX;
                                break;
                            }
                        }
                    }
                    if(ans!=INT_MAX){
                        s.push(ans);
                    }
                }
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};