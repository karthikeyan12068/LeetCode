//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        // code here 
        list<int>l1;
        int size=0,msize=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]=='A'){
                size++;
            }
            else{
                if(m!=0){
                    m--;
                    size++;
                }
                else{
                    size=i-l1.front();
                    l1.pop_front();
                }
                l1.push_back(i);
            }
            msize=max(msize,size);
        }
        return msize;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends