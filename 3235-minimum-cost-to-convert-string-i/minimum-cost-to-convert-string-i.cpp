class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>matrix(26,vector<int>(26,1e9));
        for(int i=0;i<original.size();i++){
            matrix[original[i]-'a'][changed[i]-'a']=min(matrix[original[i]-'a'][changed[i]-'a'],cost[i]);
        }
        int n=26;
        for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
				if (i == j) matrix[i][j] = 0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
				}
			}
		}
        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]!=target[i]){
                if(matrix[source[i]-'a'][target[i]-'a']==1e9){
                    return -1;
                }
                ans+=matrix[source[i]-'a'][target[i]-'a'];
            }
        }
        return ans;
    }
};