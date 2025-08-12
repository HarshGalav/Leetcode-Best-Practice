class Solution {
public:
const int MOD = 1000000007;
    int f(vector<int> &temp, int idx, int n, vector<vector<int>> &dp) {
        if (n == 0) return 1;
        if (n < 0 || idx >= temp.size()) return 0;

        if (dp[idx][n] != -1) return dp[idx][n];

        int pick = f(temp, idx + 1, n - temp[idx], dp);
        int notpick = f(temp, idx + 1, n, dp);

        return dp[idx][n] = (pick + notpick)%MOD;
    }

    int numberOfWays(int n, int x) {
        vector<int> temp;
        for (int i = 1; i <= n; i++) {
            long long val = llround(pow(i, x));
            if (val > n) break;
            temp.push_back((int)val);
        }

        vector<vector<int>> dp(temp.size(), vector<int>(n + 1, -1));
        return f(temp, 0, n, dp);
    }
};
