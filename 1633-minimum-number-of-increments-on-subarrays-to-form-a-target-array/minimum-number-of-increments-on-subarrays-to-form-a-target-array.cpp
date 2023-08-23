class Solution {
public:
    
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int s=0;
        int ext=0;
        for(int i=0;i<n;i++){
            if(i==0){
                s+=target[i];
                ext=target[i];
            }
            else{
                if(target[i]<ext){
                    ext=target[i];
                }
                else{
                    s+=target[i]-ext;
                    ext=target[i];
                }
            }
        }
        return s;
    }
};