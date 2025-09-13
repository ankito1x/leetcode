class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;

        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2; // elements from nums1
            int j = half - i;         // elements from nums2

            int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == m) ? INT_MAX : nums1[i];
            int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == n) ? INT_MAX : nums2[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 1) {
                    return max(Aleft, Bleft);
                } else {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            } else if (Aleft > Bright) {
                high = i - 1; // move left
            } else {
                low = i + 1;  // move right
            }
        }

        throw runtime_error("No median found");
    }
};
