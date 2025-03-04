class Solution {
public:
    int f(int i,int j,int k, string & s, vector<vector<vector<int>>>&dp){
        if(i>j) return 0;
        if(i==j) return 1;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int res=max(f(i + 1, j, k, s, dp),f(i,j-1,k,s,dp));
        int cost = min(abs(s[i]-s[j]), 26- abs(s[i]-s[j]));

        if(k>= cost){
            res=max(res,2+ f(i+1,j-1,k-cost,s,dp));

        }
        return dp[i][j][k]=res;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return f(0,n-1,k,s,dp);
    }
};