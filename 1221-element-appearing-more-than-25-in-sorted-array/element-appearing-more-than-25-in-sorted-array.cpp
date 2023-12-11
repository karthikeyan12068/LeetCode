class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto it:arr){
            m[it]++;
            if(m[it]>(0.25*arr.size())){
                return it;
            }
        }
        return -1;
    }
};