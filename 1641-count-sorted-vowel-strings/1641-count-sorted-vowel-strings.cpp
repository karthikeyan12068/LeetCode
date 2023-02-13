class Solution { 
public:
    int countVowelStrings(int n) {
        vector<int>v(5,1);
        n--;
        int sum=5;
        while(n--){
            sum=0;
            for(int j=1;j<5;j++){
                v[j]+=v[j-1];
                sum+=v[j];
            }
            sum++;
        }
        return sum;
    }
};