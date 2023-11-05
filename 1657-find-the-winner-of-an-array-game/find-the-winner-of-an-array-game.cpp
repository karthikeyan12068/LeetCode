class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        list<int>l1;
        for(int i=0;i<arr.size();i++){
            l1.push_back(arr[i]);
        }
        auto it1=l1.begin();
        auto it2=l1.begin();
        it2++;
        unordered_map<int,int>m;
        while(true){
            if(*it1>*it2){
                m[*it1]++;
                m[*it2]=0;
                if(m[*it1]>=k || m[*it1]>=arr.size()){
                    return *it1;
                }
                l1.push_back(*it2);
                it2++;
            }
            else{
                m[*it2]++;
                m[*it1]=0;
                if(m[*it2]>=k || m[*it2]>=arr.size()){
                    return *it2;
                }
                l1.push_back(*it1);
                it1=it2;
                it2++;
            }
        }      
        return -1;
    }
};