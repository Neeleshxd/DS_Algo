class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size() ;
        int i = 0;
        int j = 0;
        int max_freq = 0 ;
        long long  sum = 0; 
        sort(nums.begin(),nums.end()) ; 
        while( j < n ){
            sum += nums[j] ; 
            if( (long long)(j-i+1)*nums[j] - sum > k ){
              sum -= nums[i] ; 
              i++; 
            }
            max_freq = max(max_freq , j-i+1) ; 
            j++; 
        }
        return max_freq ; 
    }
};