class Solution {
public:
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        for(int i=0;i<n;i++){
            swap(points[i][0],points[i][1]);
        }
        sort(points.begin(),points.end());
        for(int i=0;i<n;i++){
            swap(points[i][0],points[i][1]);
        }
        int st=points[0][1];
        int arrow=1;
        for(int i=1;i<n;i++){
            if(points[i][0]>st){
                st=points[i][1];
                arrow++;
            }
        }
        return arrow;
    }
};