//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    
    long long solve(int X,int Y,string S){
        long long c1=0,c2=0;
        stack<char>s1;
        for(int i=0;i<S.length();i++){
            if(S[i]=='r' || S[i]=='p'){
                if(!s1.empty()){
                    if(S[i]=='p' && s1.top()=='r'){
                        c2++;
                        s1.pop();
                    }
                    else{
                        s1.push(S[i]);
                    }
                }
                else{
                    s1.push(S[i]);
                }
            }
            else{
                s1.push(S[i]);
            }
        }
        stack<char>temp;
        while(!s1.empty()){
            if(s1.top()=='r' || s1.top()=='p'){
                if(!temp.empty()){
                    if(s1.top()=='p' && temp.top()=='r'){
                        c1++;
                        temp.pop();
                    }
                    else{
                        temp.push(s1.top());
                    }
                }
                else{
                    temp.push(s1.top());
                }
            }
            else{
                temp.push(s1.top());
            }
            s1.pop();
        }
        while(!temp.empty()){
            temp.pop();
        }
        long long ans=X*c1+Y*c2;
        c1=0,c2=0;
        for(int i=0;i<S.length();i++){
            if(S[i]=='r' || S[i]=='p'){
                if(!s1.empty()){
                    if(S[i]=='r' && s1.top()=='p'){
                        c1++;
                        s1.pop();
                    }
                    else{
                        s1.push(S[i]);
                    }
                }
                else{
                    s1.push(S[i]);
                }
            }
            else{
                s1.push(S[i]);
            }
        }
        while(!s1.empty()){
            if(s1.top()=='r' || s1.top()=='p'){
                if(!temp.empty()){
                    if(s1.top()=='r' && temp.top()=='p'){
                        c2++;
                        temp.pop();
                    }
                    else{
                        temp.push(s1.top());
                    }
                }
                else{
                    temp.push(s1.top());
                }
            }
            else{
                temp.push(s1.top());
            }
            s1.pop();
        }
        long long anss=X*c1+Y*c2;
        return max(ans,anss);
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends