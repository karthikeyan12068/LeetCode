class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int val=s1.top();
            s1.pop();
            s2.push(val);
        }
        s1.push(x);
        while(!s2.empty()){
            int val=s2.top();
            s2.pop();
            s1.push(val);
        }
    }
    
    int pop() {
       int z=s1.top();
        s1.pop();
        return z;
    }
    
    int peek() {
        int z=s1.top();
        return z;
    }
    
    bool empty() {
        if(s1.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */