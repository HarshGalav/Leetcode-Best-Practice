class FindSumPairs {
public:
    vector<int>nums1;
    vector<int>nums2;
    unordered_map<int,int>freq1;
    unordered_map<int,int>freq2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2):nums1(nums1),nums2(nums2){
        for(auto i:nums1){
            freq1[i]++;
        }
        for(auto i:nums2){
            freq2[i]++;
        }
    }
    
    void add(int index, int val) {
        freq2[nums2[index]]--;
        nums2[index] +=val;
        freq2[nums2[index]]++;
    }
    
    int count(int tot) {
        int res=0;
        for(auto [a,b]:freq1){
            res+=b * freq2[tot-a];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */