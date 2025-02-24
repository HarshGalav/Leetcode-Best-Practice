class Solution {
public:
    int f(string &text1,string &text2, int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1<0 || ind2 <0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        int match=0,notm=0;
        if(text1[ind1]==text2[ind2]){
            match=1+f(text1,text2,ind1-1,ind2-1,dp);
        }
        else{
            notm=max(f(text1,text2,ind1-1,ind2,dp),f(text1,text2,ind1,ind2-1,dp));
        }
        return dp[ind1][ind2]=match+notm ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(text1,text2,n-1,m-1,dp);
    }
};