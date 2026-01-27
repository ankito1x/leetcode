class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, long long>>> graph(n), rev_graph(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1]; long long w = e[2];
            graph[u].emplace_back(v, w);
            rev_graph[v].emplace_back(u, 2 * w);  
        }
        
        vector<long long> dist(n, LLONG_MAX / 2);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(0, 0);
        
        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();
            if (cost > dist[u]) continue;
            
            
            for (auto [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
            
            for (auto [v, w] : rev_graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist[n-1] == LLONG_MAX / 2 ? -1 : dist[n-1];
    }
};
