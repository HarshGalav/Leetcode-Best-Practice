class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        int maxi=1;
        for(int x=0;x<4;x++){
            int nx=i+dx[x];
            int ny=j+dy[x];
            if(nx>=0 && ny>=0 && nx<n && ny <m && matrix[nx][ny]>matrix[i][j]){
                maxi=max(maxi,1+dfs(nx,ny,matrix,dp));
            }
        }
        return dp[i][j]=maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,dfs(i,j,matrix,dp));
            }
        }
        return maxi;
    }
};