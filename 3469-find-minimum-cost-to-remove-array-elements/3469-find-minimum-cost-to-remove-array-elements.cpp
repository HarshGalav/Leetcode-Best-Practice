class Solution {
public:
int f(int pre,int cur,vector<int>& nums,vector<vector<int>>&dp){
    if(cur==nums.size()){
        return nums[pre];
    }
    if(cur == nums.size()-1){
        return max(nums[cur],nums[pre]);
    }
    if(dp[cur][pre]!=-1) return dp[cur][pre];

    int fi=max(nums[cur],nums[cur+1])+f(pre,cur+2,nums,dp);
    int s=max(nums[pre],nums[cur])+f(cur+1,cur+2,nums,dp);
    int t=max(nums[pre],nums[cur+1])+f(cur,cur+2,nums,dp);

    return dp[cur][pre]=min({fi,s,t});
}
    int minCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,1,nums,dp);
    }
};