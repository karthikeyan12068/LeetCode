class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        heights.push_back(INT_MIN);
        stack<pair<int,pair<int,int>>>s;
        int ans=-1;
        for(int i=0;i<heights.size();i++){
            //cout<<heights[i]<<'\n';
            if(s.empty()){
                s.push({heights[i],{i,0}});
            }
            else{
                int count=0;
                
                while(!s.empty() && s.top().first>heights[i]){
                    int temp=0;
                    count+=s.top().second.second;
                    count++;
                    temp+=s.top().first*((i-s.top().second.first)+s.top().second.second);
                    s.pop();
                    ans=max(ans,temp);
                }
                
                s.push({heights[i],{i,count}});
            }
        }
        return ans;
    }
};