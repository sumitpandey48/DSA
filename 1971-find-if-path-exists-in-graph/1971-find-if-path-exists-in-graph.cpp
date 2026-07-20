class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[v] = true;
        for (int u : adj[v]) {
            if (!vis[u]) {
                dfs(u, adj, vis);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);

        dfs(source, adj, vis);

        return vis[destination];
    }
};