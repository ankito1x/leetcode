class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // Min-heap: (current_time, x, y)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        // Directions - up, down, left, right
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int t = top[0], x = top[1], y = top[2];

            // If we reached the end, return time
            if (x == n-1 && y == n-1) return t;

            for (auto &dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1; 
    }
};
