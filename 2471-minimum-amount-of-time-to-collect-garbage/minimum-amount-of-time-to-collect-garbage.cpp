class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<vector<int>>count;
        vector<int>last(3,-1);
        int i1=0;
        for(auto it:garbage){
            int g=0,p=0,m=0;
            for(auto it1:it){
                if(it1=='G'){
                    g++;
                }
                if(it1=='P'){
                    p++;
                }
                if(it1=='M'){
                    m++;
                }
            }
            if(g>0){
                last[0]=i1;
            }
            if(p>0){
                last[1]=i1;
            }
            if(m>0){
                last[2]=i1;
            }
            
            vector<int>v={g,p,m};
            count.push_back(v);
            i1++;
        }
        int ans=0;
        for(int i=0;i<garbage.size();i++){
            if(i<=last[0]){
                if(i!=0){
                    ans+=travel[i-1];
                }
                ans+=count[i][0];
            }
            if(i<=last[1]){
                if(i!=0){
                    ans+=travel[i-1];
                }
                ans+=count[i][1];
            }
            if(i<=last[2]){
                if(i!=0){
                    ans+=travel[i-1];
                }
                ans+=count[i][2];
            }
        }
        return ans;
    }
};