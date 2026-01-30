class Solution {
public:
    long long minimumCost(string source, string target, 
                          vector<string>& original, 
                          vector<string>& changed, 
                          vector<int>& cost) {
        
        if (source == target) return 0;
        
        // Collect all possible substring lengths
        unordered_set<int> possibleLengths;
        for (const string& s : original) {
            possibleLengths.insert(s.length());
        }
        
        // Map substrings to IDs
        unordered_map<string, int> stringToId;
        int nodeCount = 0;
        
        for (const string& s : original) {
            if (stringToId.find(s) == stringToId.end()) {
                stringToId[s] = nodeCount++;
            }
        }
        for (const string& s : changed) {
            if (stringToId.find(s) == stringToId.end()) {
                stringToId[s] = nodeCount++;
            }
        }
        
        // Initialize distance matrix
        const long long INF = 1e18;
        vector<vector<long long>> dist(nodeCount, vector<long long>(nodeCount, INF));
        
        for (int i = 0; i < nodeCount; i++) {
            dist[i][i] = 0;
        }
        
        // Build graph with minimum costs
        for (int i = 0; i < original.size(); i++) {
            int u = stringToId[original[i]];
            int v = stringToId[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        
        // Floyd-Warshall
        for (int k = 0; k < nodeCount; k++) {
            for (int i = 0; i < nodeCount; i++) {
                if (dist[i][k] == INF) continue; // Skip impossible paths
                for (int j = 0; j < nodeCount; j++) {
                    if (dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // DP
        int n = source.length();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;
            
            // Match single character
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            
            // Try only valid lengths
            for (int len : possibleLengths) {
                if (i + len > n) continue;
                
                string srcSub = source.substr(i, len);
                string tgtSub = target.substr(i, len);
                
                // Quick check if substrings exist
                auto itSrc = stringToId.find(srcSub);
                auto itTgt = stringToId.find(tgtSub);
                
                if (itSrc != stringToId.end() && itTgt != stringToId.end()) {
                    int u = itSrc->second;
                    int v = itTgt->second;
                    
                    if (dist[u][v] != INF) {
                        dp[i + len] = min(dp[i + len], dp[i] + dist[u][v]);
                    }
                }
            }
        }
        
        return dp[n] == INF ? -1 : dp[n];
    }
};