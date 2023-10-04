class MyHashMap {
public:
   
    set<pair<int,int>>s;
    MyHashMap() {
        s.clear();
    }
    
    void put(int key, int value) {
        pair<int,int>p=make_pair(key,0);
        auto it=s.lower_bound(p);
        if(it!=s.end()){
            if((*it).first==key){
                s.erase(it);
            }
        }
        s.insert({key,value});
    }
    
    int get(int key) {
        pair<int,int>p=make_pair(key,0);

        auto it=s.lower_bound(p);

        if(it!=s.end()){
            if((*it).first==key){
                return (*it).second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
         pair<int,int>p=make_pair(key,0);
        auto it=s.lower_bound(p);
        if(it!=s.end()){
           if((*it).first==key){
                s.erase(it);
           }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */