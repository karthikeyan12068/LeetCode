class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>m;
        for(auto it:s){
            m[it]++;
        }
        int c=0;
        for(auto it:t){
            auto it1=m.find(it);
            if(it1!=m.end()){
                it1->second--;
                if(it1->second==0){
                    m.erase(it1);
                }
            }
            else{
                c++;
            }
        }
        return c;
    }
};