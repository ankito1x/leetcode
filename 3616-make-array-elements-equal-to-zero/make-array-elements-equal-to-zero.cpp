class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, prefix = 0, suffix = 0;
        for (int x : nums) suffix += x;
        for (int i = 0; i < n; ++i) {
            suffix -= nums[i];
            prefix += nums[i];
            if (nums[i] > 0) continue;
            long long left_sum = prefix - nums[i];
            long long right_sum = suffix;
            if (left_sum == right_sum) ans += 2;
            else if (llabs(left_sum - right_sum) == 1) ans += 1;
        }
        return (int)ans;
    }
};
