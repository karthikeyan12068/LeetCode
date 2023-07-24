class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>>s;
        vector<int>v(nums.size(),-1);
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(s.empty()){
                s.push({i,nums[i]});
            }
            else{
                while(!s.empty() && s.top().second<nums[i]){
                    m[s.top().second]=nums[i];
                    v[s.top().first]=(nums[i]);
                    s.pop();
                }
                s.push({i,nums[i]});
            }
        }
        int i=0;
        while(!s.empty() && i<nums.size()){
            if(s.top().second<nums[i]){
                while(s.top().second<nums[i]){
                    v[s.top().first]=nums[i];
                    s.pop();
                }
            }
            i++;
        }
        
        return v;
    }
};