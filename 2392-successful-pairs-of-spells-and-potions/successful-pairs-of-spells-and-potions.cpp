class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;
        ans.reserve(spells.size());
        for (int s : spells) {
            long long threshold = (success + s - 1) / s;
            auto it = lower_bound(potions.begin(), potions.end(), threshold);
            int idx = it - potions.begin();
            ans.push_back(m - idx);
        }
        return ans;
    }
};
