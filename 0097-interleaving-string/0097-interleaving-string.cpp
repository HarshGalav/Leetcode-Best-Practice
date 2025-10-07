class Solution {
public:
    bool f(int idx1, int idx2, int idx3, string &s1, string &s2, string &s3, vector<vector<vector<int>>>& dp) {
        if (idx3 < 0) return true;
        if (dp[idx1 + 1][idx2 + 1][idx3 + 1] != -1) 
            return dp[idx1 + 1][idx2 + 1][idx3 + 1];
        bool ans = false;
        if (idx1 >= 0 && s1[idx1] == s3[idx3]) 
            ans = ans || f(idx1 - 1, idx2, idx3 - 1, s1, s2, s3, dp);
        if (idx2 >= 0 && s2[idx2] == s3[idx3]) 
            ans = ans || f(idx1, idx2 - 1, idx3 - 1, s1, s2, s3, dp);
        return dp[idx1 + 1][idx2 + 1][idx3 + 1] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));
        return f(n1 - 1, n2 - 1, n3 - 1, s1, s2, s3, dp);
    }
};
