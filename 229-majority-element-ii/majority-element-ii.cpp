class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0;
        int ele1=INT_MIN,ele2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            
            if(c1==0){
                if(ele2==nums[i]){
                    c2++;
                }
                else{
                    ele1=nums[i];
                    c1=1;
                }
            }
            else{
                if(c2==0){
                    if(ele1==nums[i]){
                        c1++;
                    }
                    else{
                        ele2=nums[i];
                        c2=1;
                    }
                }
                else{
                    if(ele1==nums[i]){
                        c1++;
                    }
                    else{
                        if(ele2==nums[i]){
                            c2++;
                        }
                        else{
                            c1--;
                            c2--;
                        }
                    }
                    
                }
            }
        }
        int n=nums.size()/3;
        vector<int>ans;
        int temp1=0,temp2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1){
                temp1++;
            }
            if(nums[i]==ele2){
                temp2++;
            }
        }
        if(temp1>n){
            ans.push_back(ele1);
        }
        if(temp2>n){
            ans.push_back(ele2);
        }
        return ans;
    }
};