class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
        vector<bool>ans;
        for(int i=0;i<m;i++){
            vector<int>temp;
            if(r[i]-l[i]<=1){
                ans.push_back(true);
                continue;
            }
            for(int j=l[i];j<=r[i];j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            vector<int>t=temp;
            reverse(t.begin(),t.end());
            int f1=0,f2=0,d1=temp[1]-temp[0],d2=t[1]-t[0];
            int n=temp.size();
            for(int i=2;i<n;i++){
                if(f1==0){
                    if(temp[i]-temp[i-1]!=d1){
                        f1=1;
                    }
                }
                if(f2==0){
                    if(t[i]-t[i-1]!=d2){
                        f2=1;
                    }
                }
                if(f1==1 && f2==1){
                    break;
                }
            }
            if(f1==0 || f2==0){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};