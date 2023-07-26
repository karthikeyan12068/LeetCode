class Solution {
public:
    bool hdp(double z) {
        if (ceil((float) z / 1.0) == floor((float) z / 1.0)) {
            return false;
        }
        return true;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1,r=10000000;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            double wait=0.0;
            for(int i=0;i<dist.size();i++){
                double temp=((double)dist[i])/((double)mid);
                if(hdp(temp)){
                    if(i!=dist.size()-1){
                        wait+=ceil(temp);
                    }
                    else{
                        wait+=temp;
                    }
                }
                else{
                    wait+=temp;
                }
            }
            //cout<<mid<<' '<<wait<<'\n';
            if(wait<=hour){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};