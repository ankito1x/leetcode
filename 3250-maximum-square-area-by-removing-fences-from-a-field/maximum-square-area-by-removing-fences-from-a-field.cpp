class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {

        unordered_set<int> edges;
        const int mod = 1e9 + 7;

        hFences.push_back(m);
        vFences.push_back(n);

        hFences.insert(hFences.begin(), 1);
        vFences.insert(vFences.begin(), 1);

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                edges.insert(abs(hFences[i] - hFences[j]));
            }
        }

        long long int maxi = -1;

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int side = abs(vFences[i] - vFences[j]);
                if (edges.find(side) != edges.end())
                    maxi = max(maxi, side * 1LL * side);
            }
        }

        return maxi % mod;
    }
};
