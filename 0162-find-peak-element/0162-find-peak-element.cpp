class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        
        int l = 0;
        int h = n - 1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == n - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
