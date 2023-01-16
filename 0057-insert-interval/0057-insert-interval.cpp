class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& n) {
        vector<vector<int>>v;
        int z=0;
        for(int i=0;i<in.size();i++){
            if(in[i][0]<n[0] && in[i][1]<n[0] || in[i][0]>n[1] && in[i][1]>n[1]){
                v.push_back(in[i]);
            }
            else{
                z=1;
                int st=-1,en=-1,x=i;
                st=min(in[i][0],n[0]);
                for(int j=i;j<in.size();j++){
                    if(in[j][0]<=n[1]){
                        en=max(n[1],in[j][1]);
                        x=j;
                    }
                    else{
                        break;
                    }
                }
                i=x;
                v.push_back({st,en});
            }
        }
        if(z==0){
            v.push_back(n);
            sort(v.begin(),v.end());
        }
        return v;
    }
};