class Solution {
public:
    string ret(string temp,int carry){
        if(carry==0){
            return temp;
        }
        else{
            for(int i=temp.length()-1;i>=0;i--){
                if(temp[i]=='1'){
                    temp[i]='0';
                }
                else{
                    temp[i]='1';
                    return temp;
                }
            }
            temp='1'+temp;
        }
        return temp;
    }
    string addBinary(string a, string b) {
        string temp="";
        int carry=0;
        int l1=a.length()-1,l2=b.length()-1;
        while(l1!=-1 && l2!=-1){
            
            if(a[l1]=='1' && b[l2]=='1'){
                if(carry==1){
                    temp='1'+temp;
                }
                else{
                    temp='0'+temp;
                    carry=1;
                }
            }
            else{
                if(a[l1]=='1' || b[l2]=='1'){
                    if(carry==0){
                        temp='1'+temp;
                    }
                    else{
                        temp='0'+temp;
                        carry=1;
                    }
                }
                else{
                   if(carry==1){
                       carry=0;
                       temp='1'+temp;
                   } 
                   else{
                       temp='0'+temp;
                   }
                }
            }
            l1--;
            l2--;
        }
        string ret1="";
        if(a.length()==b.length()){
            if(carry==1){
                temp='1'+temp;
            }
        }
        else{
            if(a.length()>b.length()){
                for(int i=a.length()-b.length()-1;i>=0;i--){
                    ret1=a[i]+ret1;
                }
            }
            else{
                for(int i=b.length()-a.length()-1;i>=0;i--){
                    ret1=b[i]+ret1;
                }
            }
            string rem=ret(ret1,carry);
            temp=rem+temp;
        }
        return temp;
    }
};