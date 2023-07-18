class Solution {
public:
    vector<vector<char>>ans;
    bool ret(int ind,vector<pair<int,int>>&v,map<pair<int,int>,set<int>>&m,vector<vector<char>>& board){
        
        if(!ans.empty()){
            return true;
        }
        if(ind==v.size()){
            
            ans=board;
            return true;
        }
        
        bool ans=false;
        int x=v[ind].first,y=v[ind].second;
        for(int val=1;val<=9;val++){
            int f=0;
            for(int i=0;i<9;i++){
                if(board[x][i]!='.' && (board[x][i]-'0')==val){
                    f=1;
                    break;
                }
                if(board[i][y]!='.' && (board[i][y]-'0')==val){
                    f=1;
                    break;
                }
            }
            if(f==0){
                auto it=m[{x/3,y/3}].lower_bound(val);
                if(it==m[{x/3,y/3}].end() || *it!=val){
                    m[{x/3,y/3}].insert(val);
                    board[x][y]=(char)(val+'0');
                    ans=ans|ret(ind+1,v,m,board);
                    if(ans==true){
                        break;
                    }
                    m[{x/3,y/3}].erase(val);
                    board[x][y]='.';
                }
            }
        }
        return ans;
    }
    void ret1(int i,int j,map<pair<int,int>,set<int>>&m,vector<vector<char>>& board){
        set<int>x;
        for(int i1=i;i1<i+3;i1++){
            for(int j1=j;j1<j+3;j1++){
                if(board[i1][j1]!='.'){
                    x.insert(board[i1][j1]-'0');
                }
            }
        }
        m[{i/3,j/3}]=x;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>>v;
        int g=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    v.push_back({i,j});
                    g++;
                }
            }
        }
        map<pair<int,int>,set<int>>m;
        int i=0,j=0;
        while(i<9){
            ret1(i,j,m,board);
            j+=3;
            j%=9;
            if(j==0){
                i+=3;
            }
        }
        
        ret(0,v,m,board);
        board=ans;
    }
};