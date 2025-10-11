class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> count;
        for (const int damage : power)
            ++count[damage];

        vector<int> uniqueDamages;
        for (const auto& kv : count)
            uniqueDamages.push_back(kv.first);
        sort(uniqueDamages.begin(), uniqueDamages.end());

        int n = uniqueDamages.size();
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        for (int i = 0; i < n; ++i) {
           long long damage = 1LL * uniqueDamages[i] * count[uniqueDamages[i]];
            if (i == 0) {
                dp[i][0] = 0;
                dp[i][1] = damage;
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = damage;
                if (uniqueDamages[i] - uniqueDamages[i - 1] > 2) {
                    dp[i][1] += max(dp[i - 1][0], dp[i - 1][1]);
                } else if (i >= 2 && uniqueDamages[i] - uniqueDamages[i - 2] > 2) {
                    dp[i][1] += max(dp[i - 2][0], dp[i - 2][1]);
                } else if (i >= 3) {
                    dp[i][1] += max(dp[i - 3][0], dp[i - 3][1]);
                }
            }
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
