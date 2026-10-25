
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int cnt = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;

                    bool closed = true;

                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        if (row == 0 || row == n - 1 ||
                            col == 0 || col == m - 1) {
                            closed = false;
                        }

                        for (int k = 0; k < 4; k++) {
                            int nrow = row + drow[k];
                            int ncol = col + dcol[k];

                            if (nrow >= 0 && nrow < n &&
                                ncol >= 0 && ncol < m &&
                                grid[nrow][ncol] == 0 &&
                                !visited[nrow][ncol]) {

                                q.push({nrow, ncol});
                                visited[nrow][ncol] = true;
                            }
                        }
                    }

                    if (closed) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};

