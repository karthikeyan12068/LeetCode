class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>>store;
        int f=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                int j=i;
                while(true){
                    if(j==nums.size()){
                        j--;
                        break;
                    }
                    else{
                        if(nums[j]!=1){
                            f=1;
                            j--;
                            break;
                        }
                        else{
                            j++;
                        }
                    }
                }
                store.push_back({i,j});
                
                i=j;
            }
            else{
                f=1;
            }
        }
        int ans=-1;
        if(store.empty()){
            return 0;
        }
        if(store.size()==1){
            if(f==0){
                return (store[0].second-store[0].first);
            }
            else{
                return (store[0].second-store[0].first)+1;
            }
        }
        for(int i=0;i<store.size()-1;i++){
            if(store[i+1].first-store[i].second==2){
                ans=max(ans,store[i+1].second-store[i].first);
            }
            else{
                ans=max(ans,(store[i].second-store[i].first)+1);
            }
        }
        return ans;
    }
};