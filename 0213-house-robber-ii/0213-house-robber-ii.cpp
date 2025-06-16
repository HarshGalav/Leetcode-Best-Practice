class Solution {
public:
    int f(int idx, vector<int>& nums, bool flag, vector<vector<int>>& dp) {
        if (idx < 0) return 0;
        if (idx == 0) return flag ? 0 : nums[0];
        if (dp[idx][flag] != -1) return dp[idx][flag];

        int pick = 0;
        if (idx == nums.size() - 1) {
            pick = nums[idx] + f(idx - 2, nums, true, dp);
        } else {
            pick = nums[idx] + f(idx - 2, nums, flag, dp);
        }

        int not_pick = f(idx - 1, nums, flag, dp);

        return dp[idx][flag] = max(pick, not_pick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(n - 1, nums, false, dp);
    }
};
