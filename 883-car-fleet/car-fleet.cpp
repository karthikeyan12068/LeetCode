class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<pair<double,double>>st;
        vector<pair<double,double>>v;
        int n=position.size();
        for(int i=0;i<n;i++){
            v.push_back({(double)position[i],(double)speed[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({(double)v[i].first,(double)v[i].second});
            }
            else{
                if(st.top().second<=v[i].second){
                    st.push({v[i].first,v[i].second});
                }
                else{
                    int f=0;
                    while(!st.empty() && st.top().second>v[i].second){
                        double x=(v[i].first-st.top().first)/(st.top().second-v[i].second);
                        double ans1=v[i].first+x*v[i].second;
                        double ans2=st.top().first+x*st.top().second;
                        if(ans1<=target && ans2<=target){
                            st.pop();
                        }
                        else{
                            f=1;
                            st.push({v[i].first,v[i].second});
                            break;
                        }
                    }
                    if(f==0){
                        st.push({v[i].first,v[i].second});
                        
                    }
                }
            }
        }
        /*while(!st.empty()){
            cout<<st.top().first<<' '<<st.top().second<<'\n';
            st.pop();
        }*/
        return st.size();
    }
};