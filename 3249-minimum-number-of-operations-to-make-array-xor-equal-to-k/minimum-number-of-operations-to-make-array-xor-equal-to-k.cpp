class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=-1;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                x=nums[i];
            }else{
                x=x^nums[i];
            }
        }
        int c=0;
        for(int i=0;i<32;i++){
            if((((x>>i)&1)==1 && ((k>>i)&1)==1) ||(((x>>i)&1)==0 && ((k>>i)&1)==0)){
                continue;
            }else{
                c++;
            }
        }
        return c;
    }
};