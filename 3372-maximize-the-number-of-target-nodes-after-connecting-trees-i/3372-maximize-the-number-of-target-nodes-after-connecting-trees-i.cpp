class Solution {
public:
    int bfs(int idx, const vector<vector<int>>& adj, int k, int N) {
        queue<pair<int, int>> q;
        q.push({idx, 0});
        vector<bool> visited(N, false);
        visited[idx] = true;
        int count = 0;

        while (!q.empty()) {
            int cur = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (dist > k) continue;

            count++;

            for (int nbr : adj[cur]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push({nbr, dist + 1});
                }
            }
        }

        return count;
    }

    vector<int> f(const vector<vector<int>>& edges, int k) {
        int N = edges.size() + 1;
        vector<vector<int>> adj(N);
        for (const auto& edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> result(N);
        for (int i = 0; i < N; ++i) {
            result[i] = bfs(i, adj, k, N);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> ans1 = f(edges1, k);
        vector<int> ans2 = f(edges2, k - 1);
        int maxi = *max_element(ans2.begin(), ans2.end());

        for (int i = 0; i < ans1.size(); i++) {
            ans1[i] += maxi;
        }

        return ans1;
    }
};
