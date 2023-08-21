class Solution {
public:
    int ret(vector<string>& words,int i,map<char,int>rem,vector<int>&score){
        if(i==words.size()){
            return 0;
        }
        int take=0,ntake=0;
        int c=0,s=0;
        ntake=0+ret(words,i+1,rem,score);
        for(int j=0;j<words[i].length();j++){
            if(rem[words[i][j]]>0){
                rem[words[i][j]]--;
                s+=score[words[i][j]-'a'];
            }
            else{
                c=1;
                break;
            }
        }
        if(c==0){
            take=s+ret(words,i+1,rem,score);
        }
        return max(take,ntake);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int>m;
        for(auto it:letters){
            m[it]++;
        }
        return ret(words,0,m,score);
    }
};