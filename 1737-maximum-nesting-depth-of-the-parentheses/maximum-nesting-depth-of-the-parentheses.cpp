class Solution {
public:
    int maxDepth(string s) {
        int mdepth=0,cdepth=0;
        int ans=0;
        for(auto it:s){
            if(it=='('){
                cdepth++;
                if(cdepth>mdepth){
                    mdepth=cdepth;
                }
            }else{
                if(it==')'){
                    cdepth--;
                }
            }
        }
        return mdepth;
    }
};