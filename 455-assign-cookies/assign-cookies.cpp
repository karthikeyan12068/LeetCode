class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        map<int,int>m;
        sort(s.begin(),s.end());
        for(auto it:g){
            m[it]++;
        }
        int c=0;
        for(auto it:s){
            int bis=it;
            auto it1=m.lower_bound(bis);
            if(it1->first==bis){
                it1->second--;
                if(it1->second==0){
                    m.erase(it1);
                }
                c++;
            }
            else{
                if(it1!=m.begin()){
                    
                    it1--;
                    it1->second--;
                    if(it1->second==0){
                        m.erase(it1);
                    }
                    c++;
                }
                
            }
        }
        return c;
    }
};