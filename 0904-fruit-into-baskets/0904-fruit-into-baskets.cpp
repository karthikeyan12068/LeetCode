class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        pair<int,int>p={-1,-1};
        int ans=0,size=INT_MIN;
        for(int i=0;i<fruits.size();i++){
            if(p.first==-1 || p.second==-1){
                if(p.first==-1){
                    p.first=i;
                }
                else{
                    if(fruits[p.first]!=fruits[i]){
                        p.second=i;
                        ans=p.second-p.first+1;
                        size=max(size,ans);
                    }
                }
            }
            else{
                if(fruits[i]!=fruits[p.first] && fruits[i]!=fruits[p.second]){
                    p.first=max(p.first,p.second);
                    p.second=i;
                    ans=p.second-p.first+1;
                    size=max(size,ans);
                }
                else{
                    if(fruits[i]==fruits[p.first]){
                        if(fruits[i-1]!=fruits[p.first]){
                            p.first=i;
                        }
                    }
                    else{
                        if(fruits[i-1]!=fruits[p.second]){
                            p.second=i;
                        }
                    }
                    ans++;
                    size=max(size,ans);
                }
            }
            //cout<<p.first<<" "<<p.second<<"\n";
        }
        if(p.first==-1 || p.second==-1){
            return fruits.size();
        }
        return size;
    }
};