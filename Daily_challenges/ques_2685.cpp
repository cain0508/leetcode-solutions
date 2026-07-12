class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                int V = 0, E = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    V++;
                    E += adj[node].size();
                    for (int g : adj[node]) {
                        if (!visited[g]) {
                            visited[g] = true;
                            q.push(g);
                        }
                    }
                }
                if (E == V * (V - 1))
                    ans++;
            }
        }
        return ans;
    }
};