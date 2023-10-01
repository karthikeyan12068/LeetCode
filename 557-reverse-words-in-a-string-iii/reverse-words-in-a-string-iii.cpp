class Solution {
public:
    string reverseWords(string s) {
        stringstream ans(s);
        string word;
        string temp="";
        while(ans>>word){
            reverse(word.begin(),word.end());
            temp+=word;
            temp+=" ";
        }
        temp.pop_back();
        return temp;
    }
};