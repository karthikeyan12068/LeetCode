class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string b) {
       map<char,vector<char>>m1;
        int n=s1.length();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                m1[s1[i]].push_back(s2[i]);
                m1[s2[i]].push_back(s1[i]);
            }
        }
        map<int,priority_queue <char, vector<char>, greater<>>>m2;
        map<char,int>vis;
        for(int i=0;i<n;i++){
            if(vis[s1[i]]==0 && s1[i]!=s2[i]){
                list<char>q;
                q.push_back(s1[i]);
                while(!q.empty()){
                    char temp=q.front();
                    q.pop_front();
                    if(vis[temp]==0){
                        m2[i].push(temp);
                        vis[temp]++;
                        if(!m1[temp].empty()){
                            for(auto it:m1[temp]){
                                if(vis[it]==0){
                                    q.push_back(it);
                                }
                            }
                        }
                    }
                }
            }
        }
        map<char,char>m3;
        for(auto it:m2){
            char x=it.second.top();
            it.second.pop();
            while(!it.second.empty()){
                m3[it.second.top()]=x;
                it.second.pop();
            }
        }
        string a="";
        for(int i=0;i<b.length();i++){
            if(m3[b[i]]==NULL){
                a+=b[i];
            }
            else{
                a+=m3[b[i]];
            }
        }
        return a;
        return "";
    }
};