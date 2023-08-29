class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        vector<int>pref(n+1);
        for(int i=1;i<=customers.length();i++){
            if(customers[i-1]=='Y'){
                pref[i]+=pref[i-1]+1;
                
            }
            else{
                pref[i]=pref[i-1];
            }
        }
        int n1=0,ind=0,pen=INT_MAX;
        for(int i=0;i<n;i++){
            int temppen=(pref[n]-pref[i])+n1;
            if(temppen<pen){
                pen=temppen;
                ind=i;
            }
            if(customers[i]=='N'){
                n1++;
            }
            
        }
        if(n1<pen){
            ind=n;
        }
        return ind;
    }
};