class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int>st;
        list<int>q;
        int z=0,o=0;
        for(int i=0;i<students.size();i++){
            q.push_back(students[i]);
            if(students[i]==0){
                z++;
            }else{
                o++;
            }
        }
        for(int i=sandwiches.size()-1;i>=0;i--){
            st.push(sandwiches[i]);
        }
        while(!st.empty() && !q.empty()){
            if(st.top()==q.front()){
                if(st.top()==0){
                    z--;
                }else{
                    o--;
                }
                q.pop_front();
                st.pop();
            }else{
                if((st.top()==0 && z==0) || (st.top()==1 && o==0)){
                    return q.size();
                }else{
                    while(st.top()!=q.front()){
                        q.push_back(q.front());
                        q.pop_front();
                    }
                }
            }
            
        }
        return 0;
    }
};