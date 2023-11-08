class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(t!=0){
            if(t==1){
                if(sx==fx && sy==fy){
                    return false;
                }
            }
            if(max(abs(sx-fx),abs(sy-fy))<=t){
                return true;
            }
            return false;
        }
        if(sx==fx && sy==fy){
            return true;
        }
        return false;
    }
};