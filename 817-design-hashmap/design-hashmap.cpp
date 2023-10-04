class MyHashMap {
public:
    struct ComparePairs {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
            return a.first < b.first;
        }
    };
    set<pair<int,int>,ComparePairs>s;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        pair<int,int>p=make_pair(key,0);
        auto it=s.find(p);
        if(it!=s.end()){
            s.erase(it);
        }
        s.insert({key,value});
    }
    
    int get(int key) {
        pair<int,int>p=make_pair(key,0);
        auto it=s.find(p);
        if(it!=s.end()){
            return (*it).second;
        }
        return -1;
    }
    
    void remove(int key) {
         pair<int,int>p=make_pair(key,0);
        auto it=s.find(p);
        if(it!=s.end()){
            s.erase(it);
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