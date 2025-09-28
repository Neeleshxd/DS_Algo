class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        for (int k = nums.size() - 1; k >= 2; k--) {
            if (nums[k-2] + nums[k-1] > nums[k]) {
                return nums[k-2] + nums[k-1] + nums[k];
            }
        }
        return 0; 
    }
};
