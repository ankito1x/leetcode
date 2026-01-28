class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int INF = INT_MAX / 2;
        
       
        vector<vector<vector<int>>> f(k + 1, vector<vector<int>>(m, vector<int>(n, INF)));
        f[0][0][0] = 0;
        
     
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    f[0][i][j] = min(f[0][i][j], f[0][i-1][j] + grid[i][j]);
                }
                if (j > 0) {
                    f[0][i][j] = min(f[0][i][j], f[0][i][j-1] + grid[i][j]);
                }
            }
        }
        
      
        map<int, vector<pair<int, int>>> g;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                g[grid[i][j]].push_back({i, j});
            }
        }
        
    
        for (int t = 1; t <= k; t++) {
            int minCost = INF;
            
          
            for (auto it = g.rbegin(); it != g.rend(); it++) {
                auto& positions = it->second;
                
               
                for (auto [i, j] : positions) {
                    minCost = min(minCost, f[t-1][i][j]);
                }
                
              
                for (auto [i, j] : positions) {
                    f[t][i][j] = minCost;
                }
            }
            
          
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i > 0) {
                        f[t][i][j] = min(f[t][i][j], f[t][i-1][j] + grid[i][j]);
                    }
                    if (j > 0) {
                        f[t][i][j] = min(f[t][i][j], f[t][i][j-1] + grid[i][j]);
                    }
                }
            }
        }
        
  
        int result = INF;
        for (int t = 0; t <= k; t++) {
            result = min(result, f[t][m-1][n-1]);
        }
        return result;
    }
};