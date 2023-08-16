class NumArray {
public:
    vector<int>seg;
    int x;
    void build(int ind,int l,int r,vector<int>&nums,vector<int>&seg){
        if(l==r){
            seg[ind]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*ind+1,l,mid,nums,seg);
        build(2*ind+2,mid+1,r,nums,seg);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    int query(int ind,int low,int high,int l,int r,vector<int>&seg){
        if(high<l || r<low){
            return 0;
        }
        if(low>=l && high<=r){
            return seg[ind];
        }
        int mid=(low+high)/2;
        int l1=query(2*ind+1,low,mid,l,r,seg);
        int r1=query(2*ind+2,mid+1,high,l,r,seg);
        return l1+r1;
    }
    void updateq(int ind,int l,int r,int i,int val,vector<int> &seg){
        if(l==r){
            seg[ind]=val;
            return;
        }
        int mid=(l+r)/2;
        if(i<=mid){
            updateq(2*ind+1,l,mid,i,val,seg);
        }
        else{
            updateq(2*ind+2,mid+1,r,i,val,seg);
        }
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    NumArray(vector<int>& nums) {
        seg.resize(nums.size()*4+1);
        x=nums.size()-1;
        build(0,0,nums.size()-1,nums,seg);
    }
    
    void update(int index, int val) {
        updateq(0,0,x,index,val,seg);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,x,left,right,seg);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */