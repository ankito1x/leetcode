class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len < n; ++len) {           
            for (int i = 0; i + len < n; ++i) {
                int j = i + len;
                int best = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    int cost = dp[i][k] + dp[k][j] + A[i] * A[k] * A[j];
                    best = min(best, cost);
                }
                dp[i][j] = (best == INT_MAX ? 0 : best);
            }
        }
        return dp[0][n-1];
    }
};
