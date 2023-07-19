class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        int prev=intervals[0][1];
        int c=0;
        for(int i=1;i<intervals.size();i++){
            if(prev>intervals[i][0]){
                c++;
            }
            else{
                prev=intervals[i][1];
            }
        }
        return c;
    }
};