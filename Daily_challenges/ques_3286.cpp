class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // we can use dijkstra algorithm but in this can the weights are uniform
        // like 0 or 1 so we are using 0-1 bfs
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> path(n, vector<int>(m, -1));
        // initial condition
        health -= grid[0][0];
        if (health <= 0)
            return false;
        deque<tuple<int, int, int>> dq;
        dq.push_front({0, 0, health});
        path[0][0] = health;

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!dq.empty()) {
            auto [r, c, h] = dq.front();
            dq.pop_front();

            if(h<path[r][c])
            continue;

            // checking m-1 * n-1
            if (r == n - 1 && c == m - 1)
                return true;

            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;
                int newhealth = h - grid[nr][nc];
                if (newhealth <= 0)
                    continue;
                if (newhealth <= path[nr][nc])
                    continue;

                path[nr][nc] = newhealth;
                
                //0-cost edge ->front
                if (newhealth == h) {
                        dq.push_front({nr, nc, newhealth});
                    } else {
                        dq.push_back({nr, nc, newhealth});
                    }

            }
        }
        return false;
    }
};