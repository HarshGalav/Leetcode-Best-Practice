class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int idx=lower_bound(begin(nums)+i+1,end(nums),lower-nums[i])-begin(nums);
            int x=idx-1-i;
            idx=upper_bound(begin(nums)+i+1,end(nums),upper-nums[i])-begin(nums);
            int y=idx-1-i;
            ans += (y-x);
        }
        return ans;
    }
};