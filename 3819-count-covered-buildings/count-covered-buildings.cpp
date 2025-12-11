class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,int> minY, maxY; 
        unordered_map<int,int> minX, maxX; 
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            if (!minY.count(x)) { minY[x] = y; maxY[x] = y; }
            else { minY[x] = min(minY[x], y); maxY[x] = max(maxY[x], y); }

            if (!minX.count(y)) { minX[y] = x; maxX[y] = x; }
            else { minX[y] = min(minX[y], x); maxX[y] = max(maxX[y], x); }
        }

        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            if (minY[x] < y && y < maxY[x] && minX[y] < x && x < maxX[y]) {
                ++ans;
            }
        }
        return ans;
    }
};
