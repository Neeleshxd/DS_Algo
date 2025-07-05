class Solution
{
    public:
        int numberOfSubarrays(vector<int> &nums, int k)
        {
            int n = nums.size();
            for (int i = 0; i < n; i++)
            {
                if (nums[i] % 2 == 0)
                {
                    nums[i] = 0;
                }
            }
            unordered_map<int, int> mp;
            mp[0] = 1;
            int sum = 0 ; 
            int count_sub =  0 ; 
            for (int i = 0; i < n; i++) {
                sum += nums[i] ; 
                if( sum >= k ){
                    if( mp.find(sum-k) != mp.end()){
                      count_sub += mp[sum-k] ; 
                    }
                }
                mp[sum]++; 
            }
            return count_sub ; 
        }
};