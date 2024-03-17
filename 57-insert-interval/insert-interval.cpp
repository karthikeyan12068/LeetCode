class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>&nums, vector<int>& intr) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        if(nums.empty()){
            ans.push_back(intr);
            return ans;
        }
        int f=0;
        for(int i=0;i<nums.size();i++){
            vector<int>cur=nums[i];
            if(f==0){
                if(intr[0]>=cur[0] && intr[0]<=cur[1]){
                    f=1;
                    if(intr[1]<=cur[1]){
                        ans.push_back(nums[i]);
                        continue;
                    }
                    else{
                        cur[1]=intr[1];
                        ans.push_back(cur);
                        int j=i+1;
                        while(j<nums.size() && ans.back()[1]>=nums[j][0]){
                            ans.back()[1]=max(ans.back()[1],nums[j][1]);
                            j++;
                        }
                        i=j-1;
                    }
                }
                else{
                    if(intr[1]>=cur[0] && intr[1]<=cur[1]){
                        f=1;
                        if(intr[0]==cur[0]){
                            ans.push_back(nums[i]);
                            continue;
                        }
                        else{
                            cur[0]=intr[0];
                            ans.push_back(cur);
                            int j=i+1;
                            while(j<nums.size() && ans.back()[1]>=nums[j][0]){
                                ans.back()[1]=max(ans.back()[1],nums[j][1]);
                                j++;
                            }
                            i=j-1;
                        }
                    }
                    else{
                        if(nums[i][0]>intr[1]){
                            f=1;
                            ans.push_back(intr);
                            ans.push_back(nums[i]);
                        }
                        else{
                            if(intr[0]<nums[i][0] && intr[1]>nums[i][1]){
                                cur[0]=intr[0];
                                cur[1]=intr[1];
                                int j=i+1;
                                ans.push_back(cur);
                                while(j<nums.size() && ans.back()[1]>=nums[j][0]){
                                    ans.back()[1]=max(ans.back()[1],nums[j][1]);
                                    j++;
                                }
                                i=j-1;
                                f=1;
                            }
                            else{
                                ans.push_back(nums[i]);
                            }
                        }
                    }
                }
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        if(f==0){
            if(intr[0]>ans.back()[1]){
                ans.push_back(intr);
            }
            else{
                ans.insert(ans.begin(),intr);
            }
        }
        return ans;
    }
};