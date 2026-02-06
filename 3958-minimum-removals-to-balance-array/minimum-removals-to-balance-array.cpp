class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxCount = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            long long target = (long long)nums[i] * k;
            int j = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            maxCount = max(maxCount, j - i);
        }
        
        return n - maxCount;
    }
};