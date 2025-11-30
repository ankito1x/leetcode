class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long newTarget = (long long)target - nums[i] - nums[j];
                int l = j + 1;
                int r = n - 1;

                while (l < r) {
                    long long twoSum = nums[l] + nums[r];

                    if (twoSum == newTarget) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});

                    
                        int lastL = nums[l];
                        while (l < r && nums[l] == lastL) l++;

                   
                        int lastR = nums[r];
                        while (l < r && nums[r] == lastR) r--;
                    }
                    else if (twoSum < newTarget) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};
