class Solution {
public:
    bool closeStrings(string word1, string word2) {
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        if(word1==word2){
            return true;
        }
        if(word1.length()==word2.length()){
            map<char,int>m1,m2;
            for(int i=0;i<word1.length();i++){
                m1[word1[i]]++;
                m2[word2[i]]++;
            }
            if(m1.size()==m2.size()){
                int c=0;
                vector<int>v1,v2;
                for(auto it:m1){
                    if(m2[it.first]!=NULL){
                        c++;
                    }
                    v1.push_back(it.second);
                }
                for(auto it:m2){
                    if(m1[it.first]!=NULL){
                        c++;
                    }
                    v2.push_back(it.second);
                }
                if(c==m1.size()*2){
                    sort(v1.begin(),v1.end());
                    sort(v2.begin(),v2.end());
                    if(v1==v2){
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
};