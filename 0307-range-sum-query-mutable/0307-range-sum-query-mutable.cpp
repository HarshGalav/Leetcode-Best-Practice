class NumArray {
public:
    vector<int>segmentTree;
    int n;
    void build(int i,int l,int r,const vector<int>&nums){
        if(l==r){
            segmentTree[i]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,nums);
        build(2*i+2,mid+1,r,nums);
        segmentTree[i]=segmentTree[2*i +1]+segmentTree[2*i +2];

    }
    void upd(int idx,int val, int i,int l,int r){
        if(l==r){
            segmentTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            upd(idx,val,2*i+1,l,mid);
        }
        else{
            upd(idx,val,2*i +2,mid+1,r);
        }
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    int sr(int left,int right,int idx,int l,int r){
        if(l>right || r<left ){
            return 0;
        }
        if (left <= l && r <= right)
{
            return segmentTree[idx];
        }
        int mid=l+(r-l)/2;
        return sr(left,right,2*idx +1 ,l,mid)+sr(left,right,2*idx+2,mid+1,r);
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        segmentTree.resize(4*n);
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        upd(index,val,0,0,n-1);
        
    }
    
    int sumRange(int left, int right) {
       return sr(left,right,0,0,n-1);
        
         
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */