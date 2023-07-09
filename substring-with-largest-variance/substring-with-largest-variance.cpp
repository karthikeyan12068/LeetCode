class Solution {
public:
    int largestVariance(string s) {
        int n=s.size(), max_till=0;
        unordered_set<char> st(s.begin(),s.end());
        for(char a:st) {
            for(char b:st) {
                if(a==b) continue;
                int max_here=0, b_here=0;
                for(int i=0; i<n; i++) {
                    if(s[i]==a) max_here++;
                    else if(s[i]==b) {max_here--; b_here=1;}
                    if(b_here==1) max_till=max(max_till,max_here);
                    if(max_here<0) {max_here=0; b_here=0;}
                }
                max_here=0, b_here=0;
                for(int i=n-1; i>=0; i--) {
                    if(s[i]==a) max_here++;
                    else if(s[i]==b) {max_here--; b_here=1;}
                    if(b_here!=0) max_till=max(max_till,max_here);
                    if(max_here<0) {max_here=0; b_here=0;}
                }
            }
        }
        return max_till;
    }
};