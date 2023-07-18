class LRUCache {
public:
    map<int,int>storelastseen,updatelastseen,keyvalpair;
    int las=1;
    int cap=-1;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(keyvalpair.count(key)>0){
            int las1=updatelastseen[key];
            storelastseen.erase(las1);
            storelastseen[las]=key;
            updatelastseen[key]=las;
            las++;
            return keyvalpair[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyvalpair.count(key)>0){
            auto it=updatelastseen.find(key);
            int val1=it->second;
            storelastseen.erase(val1);
            updatelastseen.erase(it);
            keyvalpair[key]=value;
            storelastseen[las]=key;
            updatelastseen[key]=las;
            las++;
        }
        else{
            if(storelastseen.size()<cap){
                storelastseen[las]=key;
                updatelastseen[key]=las;
                keyvalpair[key]=value;
                las++;
            }
            else{
                
                
                    auto it=storelastseen.begin();
                    int k=it->second;
                    keyvalpair.erase(k);
                    updatelastseen.erase(k);
                    storelastseen.erase(it);
                    storelastseen[las]=key;
                    keyvalpair[key]=value;
                    updatelastseen[key]=las;
                    las++;
                
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */