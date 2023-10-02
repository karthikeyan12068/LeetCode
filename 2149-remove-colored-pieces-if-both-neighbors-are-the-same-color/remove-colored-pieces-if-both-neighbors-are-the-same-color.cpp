class Solution {
public:
    bool winnerOfGame(string colors) {
        vector<int>alice;
        for(int i=0;i<colors.length();i++){
            if(colors[i]=='A'){
                if(i+1<colors.length() && i+2<colors.length() && colors[i+1]=='A' && colors[i+2]=='A'){
                    alice.push_back(i+1);
                    int j=i+3;;
                    while(j<colors.length() && colors[j]!='A'){
                        j++;
                    }
                    i=j-1;
                }
            }
        }
        vector<int>bob;
        for(int i=0;i<colors.length();i++){
            if(colors[i]=='B'){
                if(i+1<colors.length() && i+2<colors.length() && colors[i+1]=='B' && colors[i+2]=='B'){
                    bob.push_back(i+1);
                    int j=i+3;;
                    while(j<colors.length() && colors[j]!='B'){
                        j++;
                    }
                    i=j-1;
                }
            }
        }
        int l=0,r=0;
        if(alice.empty()){
            return false;
        }
        if(bob.empty()){
            
            return true;
        }
        while(true){
            
            if(alice[l]+1<colors.length() && colors[alice[l]+1]=='A'){
                alice[l]++;
            }
            else{
                l++;
                if(l==alice.size()){
                    return false;
                }
                else{
                    alice[l]++;
                }
            }
             if(bob[r]+1<colors.length() && colors[bob[r]+1]=='B'){
                bob[r]++;
            }
            else{
                r++;
                if(r==bob.size()){
                    return true;
                }
                else{
                    bob[r]++;
                }
            }
        }
        return true;
    }
};