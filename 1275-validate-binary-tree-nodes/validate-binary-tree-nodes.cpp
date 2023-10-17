class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]!=-1){
                continue;
            }
            vis[i]=2;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int x=q.size();
                while(x--){
                    int node=q.front();
                    
                    q.pop();
                    if(leftChild[node]!=-1){
                        if(vis[leftChild[node]]==-1){
                            vis[leftChild[node]]=1;
                            q.push(leftChild[node]);
                        }
                        else{
                            if(vis[leftChild[node]]==2 && vis[node]==2){
                                vis[leftChild[node]]=1;
                                
                            }
                            else{
                                return false;
                            }
                        }
                    }
                    if(rightChild[node]!=-1){
                        if(vis[rightChild[node]]==-1){
                            vis[rightChild[node]]=1;
                            q.push(rightChild[node]);
                        }
                        else{
                            if(vis[rightChild[node]]==2 && vis[node]==2){
                                vis[rightChild[node]]=1;
                                
                            }
                            else{
                                return false;
                            }
                        }
                    }
                }
            }
        }
        
        if(count(vis.begin(),vis.end(),2)>1){
            return false;
        }
        return true;
    }
};