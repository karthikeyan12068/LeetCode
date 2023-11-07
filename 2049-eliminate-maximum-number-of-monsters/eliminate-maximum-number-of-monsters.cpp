class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int c=0,ans=0;
        vector<pair<double,int>>v;
        for(int i=0;i<dist.size();i++){
            double temp=((double)dist[i]/(double)speed[i]);
            v.push_back({temp,i});
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<dist.size();i++){
            long long int x= speed[v[i].second]*c;
            x=dist[v[i].second]-x;
            //cout<<speed[v[i].second]<<' '<<dist[v[i].second]<<'\n';
            if(x>0){
                ans++;
                c++;
            }
            else{
                if(i==0){
                    ans++;
                    c++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};