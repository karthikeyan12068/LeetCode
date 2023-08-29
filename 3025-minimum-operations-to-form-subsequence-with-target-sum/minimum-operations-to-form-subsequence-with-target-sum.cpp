class Solution {
public:
    long long int log_a_to_base_b(long long int a, long long int b)
    {
        long double a1 = log(a) / log(b);
        long long int x=a1;
        return x;
    }
    int minOperations(vector<int>& nums, int target) {
        vector<long long int>bin1(32),bin2(32);
        for(long long int i=0;i<32;i++){
            if(((target>>i)&1)==1){
                bin1[i]=1;
            }
        }
        reverse(bin1.begin(),bin1.end());
        
        for(auto it:nums){
            bin2[log_a_to_base_b(it,2)]++;
        }
        
        reverse(bin2.begin(),bin2.end());
        
        long long int sumused=0,rightsum=0;
        long long int i1=0,c=0;
        for(long long int i=31;i>=0;i--){
            if(bin2[i]>=bin1[i]){
                long long int extra=bin2[i]-bin1[i];
                rightsum+=extra*pow(2,i1);
                i1++;
            }
            else{
                long long int cur=pow(2,i1);
                if(rightsum-sumused>=cur){
                    sumused+=cur;
                    i1++;
                }
                else{
                    
                    long long int ind=-1;
                    for(long long int j=i-1;j>=0;j--){
                        if(bin2[j]-bin1[j]>0){
                            ind=j;
                            break;
                        }
                    }
                    if(ind==-1){
                        
                        return -1;
                    }
                    c+=(i-ind);
                    for(long long int j=ind;j<=i;j++){
                        if(j==ind){
                            bin2[j]--;
                        }
                        else{
                            bin2[j]++;
                        }
                    }
                    bin2[i]++;
                    i++;
                }
            }
        }
        
        return c;

    }
};