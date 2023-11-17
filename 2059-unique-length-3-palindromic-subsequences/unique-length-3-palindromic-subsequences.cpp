class Solution {
public:
    
    int countPalindromicSubsequence(string s) {
        set<string>st;
        map<char,vector<int>>store;
        for(int i=0;i<s.length();i++){
            store[s[i]].push_back(i);
        }
        for(char i='a';i<='z';i++){
            if(store[i].empty()){
                continue;
            }
            for(int j='a';j<='z';j++){
                if(store[j].empty()){
                    continue;
                }
                for(int k='a';k<='z';k++){
                    if(store[k].empty()){
                        continue;
                    }
                    string temp="";
                    temp+=i;
                    temp+=j;
                    temp+=k;
                    if(temp.front()!=temp.back()){
                        continue;
                    }
                    
                        auto it1=lower_bound(store[i].begin(),store[i].end(),-1);
                        int ind1=it1-store[i].begin();
                        auto it2=lower_bound(store[j].begin(),store[j].end(),store[i][ind1]+1);
                        int ind2=-1;
                        if(it2!=store[j].end()){
                            ind2=it2-store[j].begin();
                        }
                        else{
                            continue;
                        }
                        auto it3=lower_bound(store[k].begin(),store[k].end(),store[j][ind2]+1);
                        int ind3=-1;
                        if(it3!=store[k].end()){
                            ind3=it3-store[k].begin();
                            
                            st.insert(temp);
                        }
                        else{
                            continue;
                        }
                    
                }
            }
        }  
        return st.size();  
    }
};