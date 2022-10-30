class Solution {
public:
    bool canMeasureWater(int x, int y, int t) {
        int steps[]={x,-x,y,-y};
        int z=x+y;
        queue<int>q;
        vector<int>vis(z+1,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==t){
                return true;
            }
            for(int i=0;i<4;i++){
                int n=node+steps[i];
                if(n>=0 && n<=z && vis[n]==0){
                    q.push(n);
                    vis[n]=1;
                }
            }
        }
        return false;
    }
};