class Solution {
public:
bool dfs(int src, int target, unordered_map<int, vector<int>>& adj, unordered_set<int>& visited) {
    if(src == target) return true;
    visited.insert(src);
    for(int neighbor : adj[src]) {
        if(visited.find(neighbor) == visited.end()) {
            if(dfs(neighbor, target, adj, visited)) return true;
        }
    }
    return false;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> adj;

    for(auto &edge : edges) {
        int u = edge[0], v = edge[1];
        unordered_set<int> visited;
        if(adj.count(u) && adj.count(v) && dfs(u, v, adj, visited)) {
            return edge; 
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return {};
}
};