class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l=0,r=0,sum=0;
        int c=0,prev=-1;
        unordered_map<int,pair<int,int>>m;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                c++;
            }
            else{
                if(prev==-1){
                    m[i]={c,0};
                    prev=i;
                    c=0;
                }
                else{
                    m[prev].second=c;
                    m[i]={c,0};
                    c=0;
                    prev=i;
                }
            }
        }
        if(prev!=-1){
            m[prev].second=c;
        }
        c=0;
        while(r<nums.size() && nums[r]%2==0){
            r++;
            l++;
        }
        while(r<nums.size()){
            if(nums[r]%2!=0){
                if(c+1==k){
                    c++;
                    sum+=(m[r].second+1)*(m[l].first+1);
                    c--;
                    l++;
                    while(l<nums.size() && nums[l]%2==0){
                        l++;
                    }
                    if(l>r){
                        r=l;
                    }
                    else{
                        if(l<=r){
                            r++;
                        }
                    }
                }
                else{
                    c++;
                    r++;
                }
            }
            else{
                r++;
            }
        }
        return sum;
    }
};