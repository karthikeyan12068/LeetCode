class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int x=nums.size();
        for(int i=0;i<x;i++){
            nums.push_back(nums[i]);
        }
        map<int,vector<int>>v;
        for(int i=0;i<nums.size();i++){
            v[nums[i]].push_back(i);
        }
        /*for(auto it:v){
            cout<<it.first<<"->\n";
            for(auto it1:it.second){
                cout<<it1<<' ';
            }
            cout<<'\n';
        }*/
        int ans=INT_MAX;
        for(auto it:v){
            int temp=INT_MIN;
            
            for(int i=1;i<it.second.size();i++){
                temp=max(temp,(int)((it.second[i]-it.second[i-1]))/2);
                if(it.second[i]>=x){
                    break;
                }
            }
            cout<<'\n';
            ans=min(ans,temp);
        }
        return ans;
    }
};