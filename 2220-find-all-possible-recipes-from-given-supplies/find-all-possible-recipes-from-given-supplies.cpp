class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,vector<string>>m;
        for(int i=0;i<recipes.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                m[ingredients[i][j]].push_back(recipes[i]);
            }
        }
        queue<string>q;
        map<string,int>deg;
        for(int i=0;i<recipes.size();i++){
            deg[recipes[i]]=ingredients[i].size();
        }
        for(int i=0;i<supplies.size();i++){
            q.push(supplies[i]);
        }
        vector<string>ans;
        while(!q.empty()){
            int x=q.size();
            while(x--){
                string cur=q.front();
                q.pop();
                for(auto it:m[cur]){
                    deg[it]--;
                    if(deg[it]==0){
                        q.push(it);
                        ans.push_back(it);
                    }
                }
            }
        }
        return ans;
    }
};