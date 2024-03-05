class Solution {
public:
    int minimumLength(string s) {
        if(s.length()==1){
            return 1;
        }
        list<char>v;
        for(auto it:s){
            v.push_back(it);
        }
        while(v.size()>1){
            char x=v.front();
            if(v.front()==v.back()){
                while(!v.empty() && v.front()==x){
                    v.pop_front();
                }
                while(!v.empty() && v.back()==x){
                    v.pop_back();
                }
            }
            else{
                break;
            }
        }
        return v.size();
    }
};