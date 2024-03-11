class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>m;
        for(int i=0;i<order.length();i++){
            m[order[i]]=i+1;
        }
        vector<pair<int,char>>v;
        for(auto it:s){
            auto it1=m.find(it);
            if(it1!=m.end()){
                v.push_back({it1->second,it});
            }
            else{
                v.push_back({INT_MAX,it});
            }
        }
        sort(v.begin(),v.end());
        string temp="";
        for(auto it:v){
            temp+=it.second;
        }
        return temp;
    }
};