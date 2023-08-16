class Solution {
public:
    long long int str_to_in(string s)
    {
        stringstream geek(s);
        long long int x = 0ll;
        geek >> x;
        return x;
    }
    int nextGreaterElement(int n) {
        string temp=to_string(n);
        if(n==INT_MAX || temp.length()<=1){
            return -1;
        }
        
        int x=-1;
        for(int i=temp.length()-2;i>=0;i--){
            int ind=-1,val=temp[i]-'0';
            for(int j=i+1;j<temp.length();j++){
                int v=temp[j]-'0';
                if(v>val){
                    ind=j;
                }
            }
            if(ind!=-1){
                swap(temp[i],temp[ind]);
                x=i;
                break;
            }
        }
        if(x==-1){
            return -1;
        }
        sort(temp.begin()+x+1,temp.end());
        if(temp.length()<=32){
            long long int x1=str_to_in(temp);
            if(x1>INT_MAX){
                return -1;
            }
            if(x1>0){
                return x1;
            }
        }
        return -1;
    }
};