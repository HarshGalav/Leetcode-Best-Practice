class Solution {
public:
    bool f(long long val, int ind, vector<int>& nums, long long target) {
        if (val == target) {
            return true;
        }
        if (ind >= nums.size()) {
            return false;
        }
        if (f( (__int128) val * nums[ind], ind + 1, nums, target)) {
            return true;
        }
        if (f(val, ind + 1, nums, target)) {
            return true;
        }
        return false;
    }

    bool checkEqualPartitions(vector<int>& nums, long long target) {
         __int128 total = 1;
        for (auto i : nums) {
            total *= i;
        }
        if ((__int128)target * target != total) {
            return false;
        }
        return f(1, 0, nums, target);
    }
};
