class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = nums[0];
        int second = INT_MAX;
        int third = INT_MAX;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < second) {
                third = second;
                second = nums[i];
            } else if (nums[i] < third) {
                third = nums[i];
            }
        }
        
        return first + second + third;
    }
};