class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, 
                          vector<char>& changed, vector<int>& cost) {
       
        const long long INF = 1e18;
        vector<vector<long long>> g(26, vector<long long>(26, INF));
        
        
        for (int i = 0; i < 26; i++) {
            g[i][i] = 0;
        }
        
       
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            g[u][v] = min(g[u][v], (long long)cost[i]);
        }
        
       
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
        
       
        long long totalCost = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                
                if (g[u][v] >= INF) {
                    return -1;  
                }
                totalCost += g[u][v];
            }
        }
        
        return totalCost;
    }
};