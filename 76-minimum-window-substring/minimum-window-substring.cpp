class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>v1(125);
        int x=0;
        for(auto it:t){
            if(v1[(int)it]==0){
                x++;
            }
            v1[(int)it]++;
        }
        vector<int>v2(125);
        int l=0,r=0;
        int sum=0;
        list<char>l1;
        int len=0;string ans="";
        while(r<s.length()){
            l1.push_back(s[r]);
            v2[(int)s[r]]++;
            if(v1[(int)s[r]]!=0 && v1[(int)s[r]]==v2[(int)s[r]]){
                
                sum++;
            }
            
            if(sum==x){
               
                while(sum==x){
                   
                    v2[(int)s[l]]--;
                    
                    if(v2[(int)s[l]]<v1[(int)s[l]]){
                        
                        sum--;
                        if(ans.empty() || ans.length()>l1.size()){
                            string temp="";
                            for(auto it:l1){
                                temp+=it;
                            }
                            ans=temp;
                        }
                    }
                    
                    l1.pop_front();
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};