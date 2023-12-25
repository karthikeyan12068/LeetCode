class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>matrix(26,vector<long long>(26,INT_MAX));
        for(int i=0;i<original.size();i++){
            int x=original[i]-'a',y=changed[i]-'a';
            matrix[x][y]=min(matrix[x][y],(long long)cost[i]);
        }
        int n=26;
        

		for (int k = 0; k < 26; k++) {
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
                    long long v=matrix[i][k] + matrix[k][j];
                    matrix[i][j] = min(matrix[i][j],v);
                    
				}
			}
		}
        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]!=target[i]){
                if(matrix[source[i]-'a'][target[i]-'a']==LONG_MAX){
                    return -1;
                }
                int x=source[i]-'a',y=target[i]-'a';
                if(matrix[x][y]>=INT_MAX){
                    return -1;
                }
                ans+=matrix[x][y];
            }
        }
        return ans;
    }
};