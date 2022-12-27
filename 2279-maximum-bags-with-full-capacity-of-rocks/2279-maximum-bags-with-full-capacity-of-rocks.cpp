class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        vector<int>rem;
        int c=0;
        int n=capacity.size();
        for(int i=0;i<n;i++){
            if(capacity[i]-rocks[i]==0){
                c++;
            }
            else{
                rem.push_back(capacity[i]-rocks[i]);
            }
        }
        sort(rem.begin(),rem.end());
        for(auto it:rem){
            a-=it;
            if(a>=0){
                c++;
            }
            else{
                break;
            }
        }
        return c;
    }
};