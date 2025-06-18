class Solution {
public:
    int f(int idx,vector<int>nums,int target,vector<vector<int>>&dp,int offset){
        if (target + offset < 0 || target + offset >= dp[0].size()) return 0;
        if(dp[idx][target+offset]!=-1){
            return dp[idx][target+offset];
        }
        if(idx==0){
            if(target == nums[0] && target == -nums[0]){
                return 2;
            }
            if(target==nums[0] || target == -nums[0]){
                return 1;
            }
            
            return 0;
            
        }
        int minus =f(idx-1,nums,target-nums[idx],dp,offset);
        int addd=f(idx-1,nums,target+nums[idx],dp,offset);

        return dp[idx][target+offset]=minus+addd;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int total=0;
        for(auto i:nums){
            total+=abs(i);
        }
        int offset=total;
        if(abs(target)>total) return 0;
        vector<vector<int>>dp(n,vector<int>(total*2+1,-1));
        return f(n-1,nums,target,dp,offset);
    }
};