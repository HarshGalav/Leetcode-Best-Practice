class Solution {
public:
    int dfs(int i, unordered_map<int, vector<int>>& mp, vector<int>& quiet, vector<int>& ans) {
        if (ans[i] != -1) return ans[i];

        int val = i;
        for (auto n : mp[i]) {
            int candidate = dfs(n, mp, quiet, ans);
            if (quiet[candidate] < quiet[val]) {
                val = candidate;
            }
        }
        return ans[i] = val;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        unordered_map<int, vector<int>> mp;
        vector<int> ans(quiet.size(), -1);

        for (auto i : richer) {
            int a = i[0];
            int b = i[1];
            mp[b].push_back(a);
        }

        for (int i = 0; i < quiet.size(); i++) {
            dfs(i, mp, quiet, ans);
        }

        return ans;
    }
};
