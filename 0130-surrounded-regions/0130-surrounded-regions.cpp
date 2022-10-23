#define count2(v,s) count((v).begin(),(v).end(),(s))
class Solution {
public:
    void mark(vector<vector<char>>& v1,int i,int j,bool t){
        if(i<=0 || j<=0 || i>=v1.size()-1 || j>=v1[0].size()-1){
            return;
        }
        if(v1[i][j]=='X' || v1[i][j]=='O'){
            return;
        }
        if(v1[i][j]=='-'){
            if(t==true){
                v1[i][j]='X';
            }
            else{
                v1[i][j]='O';
            }
        }
        mark(v1,i-1,j,t);
        mark(v1,i+1,j,t);
        mark(v1,i,j-1,t);
        mark(v1,i,j+1,t);
        return;
    }
    bool dfs(vector<vector<char>>&v1,int i,int j,int r,int c){
        //cout<<i<<" "<<j<<"\n";
        if(i==0 || j==0 || i==r-1 || j==c-1){
            if(v1[i][j]=='O'){
                return false;
            }
            return true;
        }
        if(v1[i][j]=='X' || v1[i][j]=='-'){
            return true;
        }
        else{
            v1[i][j]='-';
        }
        bool x1=dfs(v1,i-1,j,r,c);
        bool x2=dfs(v1,i+1,j,r,c);
        bool x3=dfs(v1,i,j-1,r,c);
        bool x4=dfs(v1,i,j+1,r,c);
        return x1 && x2 && x3 && x4;
    }
    void solve(vector<vector<char>>& v1) {
        int r=v1.size();
        int c=v1[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i!=0 && j!=0 && i!=r-1 && j!=c-1 && v1[i][j]=='O'){
                    if(dfs(v1,i,j,r,c)){
                        mark(v1,i,j,true);
                    }
                    else{
                        mark(v1,i,j,false);
                    }
                }
            }
        }
    }
};