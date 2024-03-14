class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal>0){
            
            unordered_map<int,pair<int,int>>m;
            int c=0,prev=-1;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==0){
                    c++;
                }
                else{
                    if(prev==-1){
                        prev=i;
                        m[i]={c,0};
                        c=0;
                    }
                    else{
                        m[prev].second=c;
                        prev=i;
                        m[i]={c,0};
                        c=0;
                    }
                }
            }
            if(prev!=-1){
                m[prev].second=c;
            }
            
            c=0;
            int l=0,r=0,sum=0;
            while(r<nums.size() && nums[r]!=1){
                r++;
                l++;
            }
            while(r<nums.size()){
                sum+=nums[r];
                if(sum==goal){
                    cout<<l<<' '<<r<<'\n';
                    c+=(m[l].first+1)*(m[r].second+1);
                    l++;
                    while(l<nums.size() && nums[l]!=1){
                        l++;
                    }
                    if(l>r){
                        r=l;
                        sum=1;
                    }
                    if(l<=r){
                        r++;
                    }
                    sum-=1;
                }
                else{
                    r++;
                }
            }
            return c;
        }
        int sum=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                int j;
                for(j=i;j<nums.size();j++){
                    if(nums[j]!=0){
                        break;
                    }
                }
                int x=j-i;
                c+=(x*(x+1))/2;
                i=j;
            }
        }
        return c;
    }
};