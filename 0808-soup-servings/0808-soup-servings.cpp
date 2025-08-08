class Solution {
public:
    double f(int a,int b,vector<vector<double>>&dp){
        if(a<=0 && b>0){
            return 1;
        }
        if(a <=0 && b <= 0){
            return 0.5;
        }
        
        if (b <= 0 && a > 0) return 0.0;
        if(dp[a][b] !=-1){
            return dp[a][b];
        }
        vector<vector<int>>v={{100,0},{75,25},{50,50},{25,75}};
        double ans=0;
        for(int i=0;i<4;i++){
           int x = max(0, a - v[i][0]);
            int y = max(0, b - v[i][1]);
            ans += 0.25 * f(x, y, dp);
        }
        return dp[a][b]=ans;
    }
    double soupServings(int n) {
        if (n >= 4800) return 1.0;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        return f(n,n,dp);
    }
};