class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<vector<int>>q;
        q.push({0});
        vector<vector<int>>v;
        while(!q.empty()){
            if(q.front().back()==n-1){
                v.push_back(q.front());
                q.pop();
            }
            else{
                for(int i=0;i<graph[q.front().back()].size();i++){
                    vector<int>temp=q.front();
                    temp.push_back(graph[q.front().back()][i]);
                    q.push(temp);
                }
                q.pop();
            }
        }
        return v;
    }
};