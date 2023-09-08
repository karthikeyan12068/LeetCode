class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v(numRows);
        for(int i=0;i<numRows;i++){
            if(i==0){
                v[i].push_back(1);
            }
            else{
                if(i==1){
                    v[i].push_back(1);
                    v[i].push_back(1);
                }
                else{
                    int size=v[i-1].size()+1;
                    for(int k=0;k<size;k++){
                        if(k!=0 && k!=size-1){
                            v[i].push_back(v[i-1][k-1]+v[i-1][k]);
                        }
                        else{
                            v[i].push_back(1);
                        }
                    }
                }
            }
        }
        return v;
    }
};