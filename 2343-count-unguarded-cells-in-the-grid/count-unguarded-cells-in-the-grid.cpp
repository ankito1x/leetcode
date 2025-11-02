class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (const auto& guard : guards) grid[guard[0]][guard[1]] = 2;
        for (const auto& wall : walls) grid[wall[0]][wall[1]] = 2;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (const auto& guard : guards) {
            for (int dir = 0; dir < 4; ++dir) {
                int x = guard[0], y = guard[1];
                while (true) {
                    x += dx[dir];
                    y += dy[dir];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2) break;
                    if (grid[x][y] == 0) grid[x][y] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0) ++res;
        return res;
    }
};
