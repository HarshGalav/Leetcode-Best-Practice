class Solution {
public:
    int f(vector<vector<int>> &grid, int m, int n, int k, int cnt,
          vector<vector<vector<int>>> &dp) {

        if (m == 0 && n == 0) {
            return ((cnt + grid[0][0]) % k == 0);
        }

        if (m < 0 || n < 0) return 0;

        int rem = cnt % k;

        if (dp[m][n][rem] != -1) return dp[m][n][rem];

        int up = f(grid, m, n - 1, k, cnt + grid[m][n], dp);
        int left = f(grid, m - 1, n, k, cnt + grid[m][n], dp);

        return dp[m][n][rem] = (up + left)%1000000007;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k, -1))
        );

        return f(grid, m - 1, n - 1, k, 0, dp);
    }
};
