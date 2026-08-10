class disjoint {
    vector<int> parent, size;

public:
    disjoint(int x) {
        parent.resize(x);
        size.resize(x, 1);
        for (int i = 0; i < x; i++) {
            parent[i] = i;
        }
    }
    int ultimateparent(int curr) {
        if (parent[curr] == curr)
            return curr;
        return parent[curr] = ultimateparent(parent[curr]);
    }
    void unionbysize(int u, int v) {
        u = ultimateparent(u);
        v = ultimateparent(v);
        if (u == v)
            return;
        if (size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        disjoint ds(n * n);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vector<pair<int, pair<int, int>>> cell;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cell.push_back({grid[i][j], {i, j}});
            }
        }
        sort(cell.begin(), cell.end());
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (auto& it : cell) {
            int height = it.first;
            int row = it.second.first;
            int col = it.second.second;
            int node = row * n + col;
            visited[row][col] = true;
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    visited[nr][nc] == true) {
                    int adj = nr * n + nc;
                    ds.unionbysize(adj, node);
                }
            }
            if (ds.ultimateparent(0) == ds.ultimateparent(n * n - 1)) {
                return height;
            }
        }
        return -1;
    }
};