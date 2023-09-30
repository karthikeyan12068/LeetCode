class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int,int>left,right;
        for(int i=0;i<nums.size();i++){
            right[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            right[nums[i]]--;
            if(right[nums[i]]==0){
                right.erase(nums[i]);
            }
            if(left.empty()){
                left[nums[i]]++;
                continue;
            }
            else{
                if(right.empty()){
                    continue;
                }
                auto it=left.begin();
                int val1=it->first;
                it=right.upper_bound(val1);
                if(it!=right.end()){
                    
                    int val2=it->first;
                    if(nums[i]>val1 && nums[i]>val2 && val2>val1){
                        return true;
                    }
                }
                
            }
            left[nums[i]]++;
        }
        return false;
    }
};