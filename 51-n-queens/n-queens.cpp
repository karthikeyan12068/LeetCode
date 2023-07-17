class Solution {
public:
    vector<vector<string>>v1;
    void ret(int i,int n,vector<string>&ans,unordered_map<int,int>&col){
        if(i==n){
            v1.push_back(ans);
            return;
        }
        if(i==0){
            for(int j=0;j<n;j++){
                ans[i][j]='Q';
                col[j]=1;
                ret(i+1,n,ans,col);
                ans[i][j]='.';
                col[j]=0;
            }
        }
        else{
            for(int j=0;j<n;j++){
                if(col[j]==0){
                    int f=0;
                    int x1=i-1,y1=j-1;
                    while(x1>=0 && y1>=0){
                        if(ans[x1][y1]=='Q'){
                            f=1;
                            break;
                        }
                        x1--;
                        y1--;
                    }
                    if(f==0){
                        x1=i-1,y1=j+1;
                        while(x1>=0 && y1>=0){
                            if(ans[x1][y1]=='Q'){
                                f=1;
                                break;
                            }
                            x1--;
                            y1++;
                        }
                        if(f==0){
                            ans[i][j]='Q';
                            col[j]=1;
                            ret(i+1,n,ans,col);
                            ans[i][j]='.';
                            col[j]=0;
                        }
                    }
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>ans;
        for(int i=0;i<n;i++){
            string temp;
            for(int j=0;j<n;j++){
                temp+='.';
            }
            ans.push_back(temp);
        }
        unordered_map<int,int>col;
        ret(0,n,ans,col);
        return v1;
    }
};