unordered_map<char,int>m;
bool cmp(string a,string b){
    int n=min(a.length(),b.length());
    for(int i=0;i<n;i++){
        if(m[a[i]]<m[b[i]]){
            return true;
        }
        if(m[a[i]]>m[b[i]]){
            return false;
        }
    }
    if(a.length()<=b.length()){
        return true;
    }
    return false;
}
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string>v;
        v=words;
        for(int i=0;i<order.length();i++){
            m[order[i]]=i+1;
        }
        sort(v.begin(),v.end(),cmp);
        if(v==words){
            return true;
        }
        return false;
    }
};