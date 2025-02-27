class Solution {
public:
    int f(int left, int right, vector<int>& cuts, vector<vector<int>>& dp) {
        if (left + 1 == right) return 0; 

        if (dp[left][right] != -1) return dp[left][right];

        int cost = INT_MAX;
        for (int i = left + 1; i < right; i++) { 
            int currentCost = (cuts[right] - cuts[left]) +
                              f(left, i, cuts, dp) +
                              f(i, right, cuts, dp);
            cost = min(cost, currentCost);
        }

        return dp[left][right] = cost;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        return f(0, m - 1, cuts, dp);
    }
};
