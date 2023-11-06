class SeatManager {
public:
    map<int,int>m;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            m[i]++;
        }
    }
    
    int reserve() {
        auto it=m.begin();
        int ans=it->first;
        m.erase(it);
        return ans;
    }
    
    void unreserve(int seatNumber) {
        m[seatNumber]++;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */