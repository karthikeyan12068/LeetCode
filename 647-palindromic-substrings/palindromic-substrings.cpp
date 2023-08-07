class Solution {
public:
    int countSubstrings(string s) {
        int sum=s.length();
        for(int i=0;i<s.length();i++){
            int i1=i;
            int j1=i1-1,j2=i1+1;
            while(j1>=0 && j2<s.length() && s[j1]==s[j2]){
                sum++;
                j1--;
                j2++;
            }
            j1=i1+1;
            while(i1>=0 && j1<s.length() && s[i1]==s[j1]){
                sum++;
                i1--;
                j1++;
            }
        }
        return sum;
    }
};