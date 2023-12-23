class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int>m;
        map<char,pair<int,int>>way;
        way['N']={-1,0};
        way['S']={+1,0};
        way['E']={0,+1};
        way['W']={0,-1};
        int x1=0,y1=0;
        m[{x1,y1}]++;
        for(auto it:path){
            x1+=way[it].first;
            y1+=way[it].second;
            if(m[{x1,y1}]>0){
                return true;
            }
            m[{x1,y1}]++;
        }
        return false;
    }
};