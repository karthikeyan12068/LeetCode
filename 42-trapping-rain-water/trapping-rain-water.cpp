class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>l(height.size()),r(height.size());
        int prev=-1;
        for(int i=height.size()-1;i>=0;i--){
            if(prev==-1){
                l[i]=height[i];
                prev=i;
            }else{
                if(height[prev]<=height[i]){
                    prev=i;
                    l[i]=height[i];
                }else{
                    l[i]=height[prev];
                }
            }
        }
        prev=-1;
        for(int i=0;i<height.size();i++){
            if(prev==-1){
                r[i]=height[i];
                prev=i;
            }else{
                if(height[prev]<=height[i]){
                    prev=i;
                    r[i]=height[i];
                }else{
                    r[i]=height[prev];
                }
            }
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=abs(height[i]-min(l[i],r[i]));
        }
        
        return ans;
    }
};