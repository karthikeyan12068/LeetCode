class Solution {
public:
    void buildGraph(vector<vector<string>>& equations,vector<double>& values,map<string,vector<pair<string,double>>>&m1){
        for(int i=0;i<values.size();i++){
            //from src to des
            m1[equations[i][0]].push_back({equations[i][1],values[i]});
            //frm des to src
            m1[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        return;
    }
    //double aa=-1.0;
    double helper(string src,string des,map<string,vector<pair<string,double>>>m1,map<string,int>&vis){
        if(src==des){
            return 1.0;
        }
        if(vis[src]==1){
            return -1.0;
        }
        vis[src]=1;
        double z=-1.0;
        for(int i=0;i<m1[src].size();i++){
            double ans=m1[src][i].second*helper(m1[src][i].first,des,m1,vis);
            z=max(z,ans);
        }
        return z;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //step1 : graph building
        
        //source node with <destination,val> as a pair
        map<string,vector<pair<string,double>>>m1;
        //building graph
        buildGraph(equations,values,m1);
        //result vec
        int n=queries.size();
        /*for(auto it:m1){
            cout<<it.first<<"\n";
            for(auto it1:it.second){
                cout<<it1.first<<" "<<it1.second<<"\n";
            }
        }*/
        vector<double>result(n);
        for(int i=0;i<n;i++){
            //if the src and destination are present in the graph
            
            if(!m1[queries[i][0]].empty() && !m1[queries[i][1]].empty()){
                if(queries[i][0]==queries[i][1]){
                    result[i]=1.0;
                }
                else{
                    map<string,int>vis;
                    result[i]=helper(queries[i][0],queries[i][1],m1,vis);
                    if(result[i]<0){
                        result[i]=-1.0;
                    }
                }
            }
            else{
                result[i]=-1.0;
            }
        }
        return result;
    }
};