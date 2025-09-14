class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; // value -> index
        for (int i = 0; i < (int)nums.size(); ++i) {
            int comp = target - nums[i];
            auto it = mp.find(comp);
            if (it != mp.end()) return {it->second, i};
            mp[nums[i]] = i;
        }
        return {};
    }
};
