class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string t1="",t2="";
        for(auto it:word1){
            t1+=it;
        }
        for(auto it:word2){
            t2+=it;
        }
        return t1==t2;
    }
};