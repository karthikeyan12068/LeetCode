class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()==word2.length()){
            sort(word1.begin(),word1.end());
            sort(word2.begin(),word2.end());
            if(word1==word2){
                return true;
            }
            set<char>s1,s2;
            map<char,int>m1,m2;
            for(auto it:word1){
                s1.insert(it);
                m1[it]++;
            }
            for(auto it:word2){
                s2.insert(it);
                m2[it]++;
            }
            if(s1==s2){
                map<int,int>have,tosearch;
                for(auto it:m1){
                    auto it1=m2.find(it.first);
                    if(it.second!=it1->second){
                        have[it.second]++;
                        tosearch[it1->second]++;
                    }
                }
                for(auto it:tosearch){
                    auto it1=have.find(it.first);
                    if(it1==have.end()){
                        return false;
                    }
                    if(it1->second!=it.second){
                        return false;
                    }
                    have.erase(it1);
                }
                return have.empty();
                
            }
            return false;
        }
        return false;
    }
};