class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;
        vector<vector<int>> score(n, vector<int>(n, 0));
        vector<vector<int>> paths(n, vector<int>(n, 0));
        paths[n - 1][n - 1] = 1;
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {1, 1}};
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X')
                    continue;

                if (board[i][j] == 'S')
                    continue;
                for (auto [a, b] : dirs) {
                    int x = i + a, y = j + b;
                    if (x >= n || y >= n)
                        continue;
                    if (score[x][y] > score[i][j]) {
                        score[i][j] = score[x][y];
                        paths[i][j] = paths[x][y];
                    } else if (score[x][y] == score[i][j]) {
                        paths[i][j] += paths[x][y];
                        paths[i][j] %= MOD;
                    }
                }
                if (paths[i][j] > 0 && board[i][j] != 'E') {
                    score[i][j] += board[i][j] - '0';
                }
            }
        }
        return paths[0][0] ? vector<int>{score[0][0], paths[0][0]}
                           : vector<int>{0, 0};
    }
};