class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        
        vector<vector<int>> row(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diag1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diag2(m + 1, vector<int>(n + 2, 0));

       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i + 1][j + 1] = row[i + 1][j] + grid[i][j];
                col[i + 1][j + 1] = col[i][j + 1] + grid[i][j];
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        
        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    int target = row[i + 1][j + k] - row[i + 1][j];
                    bool ok = true;

                 
                    for (int r = 0; r < k; r++) {
                        if (row[i + r + 1][j + k] - row[i + r + 1][j] != target) {
                            ok = false; break;
                        }
                    }

                   
                    for (int c = 0; c < k && ok; c++) {
                        if (col[i + k][j + c + 1] - col[i][j + c + 1] != target) {
                            ok = false; break;
                        }
                    }

                    
                    if (ok) {
                        int d1 = diag1[i + k][j + k] - diag1[i][j];
                        int d2 = diag2[i + k][j] - diag2[i][j + k];
                        if (d1 != target || d2 != target) ok = false;
                    }

                    if (ok) return k;
                }
            }
        }
        return 1; 
    }
};
