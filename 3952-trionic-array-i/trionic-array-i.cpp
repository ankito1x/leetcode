class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        
        for (int p = 1; p < n - 1; p++) {
            for (int q = p + 1; q < n - 1; q++) {
                bool increasing1 = true;
                for (int i = 0; i < p; i++) {
                    if (nums[i] >= nums[i + 1]) {
                        increasing1 = false;
                        break;
                    }
                }
                
                bool decreasing = true;
                for (int i = p; i < q; i++) {
                    if (nums[i] <= nums[i + 1]) {
                        decreasing = false;
                        break;
                    }
                }
                
                bool increasing2 = true;
                for (int i = q; i < n - 1; i++) {
                    if (nums[i] >= nums[i + 1]) {
                        increasing2 = false;
                        break;
                    }
                }
                
                if (increasing1 && decreasing && increasing2) {
                    return true;
                }
            }
        }
        
        return false;
    }
};