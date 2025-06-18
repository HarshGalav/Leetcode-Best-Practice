class Solution {
public:
    int f(int idx,vector<int>coins,int amount,vector<vector<int>>&dp){
        if(amount <0){
            return 0;
        }
        if(dp[idx][amount]!=-1){
            return dp[idx][amount];
        }
        if(idx==0){
            if(amount%coins[0]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(amount ==0){
            return 1;
        }
        int take=f(idx,coins,amount-coins[idx],dp);
        int nottake=f(idx-1,coins,amount,dp);
        return dp[idx][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,coins,amount,dp);
    }
};