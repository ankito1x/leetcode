class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int maxSum = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            maxSum = std::max(maxSum, nums[left] + nums[right]);
            left++;
            right--;
        }
        return maxSum;
    }
};
