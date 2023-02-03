class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        vector<vector<char>>v(numRows,vector<char>(s.length(),'$'));
        int i=0,j=0,f=0;
        for(auto it=s.begin();it!=s.end();it++){
            if(f==0){
                v[i][j]=*it;
                i++;
            }
            else{
                if(f==1){
                    v[i][j]=*it;
                    i--;
                    j++;
                }
            }
            if(i==numRows-1){
                it++;
                if(it!=s.end()){
                    v[i][j]=*it;
                    i--;
                    j++;
                    f=1;
                }
                else{
                    break;
                }
            }
            if(i==0){
                f=0;
            }
        }
        string ret="";
        for(int k=0;k<numRows;k++){
            for(int l=0;l<=j;l++){
                if(v[k][l]!='$'){
                    ret+=v[k][l];
                }
            }
        }
        return ret;
    }
};