class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = 1;
        for (int nxt : graph[node]) {
            if (!vis[nxt])
                dfs(nxt, graph, vis);
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for (auto &e : invocations)
            graph[e[0]].push_back(e[1]);
        vector<int> vis(n, 0);
        dfs(k, graph, vis);
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];
            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};