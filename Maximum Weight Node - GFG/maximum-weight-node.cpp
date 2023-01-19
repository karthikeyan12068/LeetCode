//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      unordered_map<int,int>m1;
      int sum=INT_MIN,val=INT_MIN;
      for(int i=0;i<Edge.size();i++){
          m1[Edge[i]]+=i;
          if(sum<=m1[Edge[i]]){
              if(sum==m1[Edge[i]]){
                  val=max(val,Edge[i]);
              }
              else{
                sum=max(sum,m1[Edge[i]]);
                val=Edge[i];
              }
          }
      }
      if(val==-1){
        for(int i=0;i<Edge.size();i++){
            if(Edge[i]==-1){
                val=i;
            }  
        }
      }
      return val;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends