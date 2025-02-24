class Solution {
public:
    int f(int cur,int pre,vector<int>& nums,int n, vector<vector<int>>&dp){
        if(cur==n){
            return 0;
        }
        if(dp[cur][pre+1]!=-1) return dp[cur][pre+1];
        int nottake=f(cur+1,pre,nums,n,dp);
        int take=0;
        if(pre==-1 || nums[cur]>nums[pre]){
             take=1+f(cur+1,cur,nums,n,dp);
        }
        return dp[cur][pre+1]= max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
    }
};