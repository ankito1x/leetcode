class Solution {
public:
    struct Cell {
        int r, c, h;
        bool operator>(const Cell& other) const {
            return h > other.h;
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        // Add all boundary cells
        for (int i = 0; i < m; i++) {
            pq.push({i, 0, heightMap[i][0]});
            pq.push({i, n - 1, heightMap[i][n - 1]});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({0, j, heightMap[0][j]});
            pq.push({m - 1, j, heightMap[m - 1][j]});
            visited[0][j] = visited[m - 1][j] = true;
        }

        int totalWater = 0;
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            Cell cell = pq.top();
            pq.pop();

            for (auto& d : dirs) {
                int nr = cell.r + d[0];
                int nc = cell.c + d[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;

                visited[nr][nc] = true;
                int nh = heightMap[nr][nc];

                if (nh < cell.h) {
                    totalWater += cell.h - nh; 
                }

                pq.push({nr, nc, max(nh, cell.h)});
            }
        }

        return totalWater;
    }
};
