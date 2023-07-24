class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>pref(height.size()),suf(height.size());
        int prev=-1;
        for(int i=0;i<height.size();i++){
            if(height[i]>prev){
                prev=height[i];
                pref[i]=height[i];
            }
            else{
                pref[i]=prev;
            }
        }
        prev=-1;
        for(int i=height.size()-1;i>=0;i--){
            if(height[i]>prev){
                prev=height[i];
                suf[i]=height[i];
            }
            else{
                suf[i]=prev;
            }
        }
        int sum=0;
        for(int i=0;i<height.size();i++){
            sum+=(min(pref[i],suf[i])-height[i]);
        }
        return sum;
    }
};