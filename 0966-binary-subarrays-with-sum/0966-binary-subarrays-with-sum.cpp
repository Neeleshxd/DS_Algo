class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size() ; 
        unordered_map<int,int>mp ; 
        mp[0] = 1 ;
        int prefix_sum = 0 ;
        int sub = 0 ; 
        for( int i = 0 ;i < n ; i++ ){
         prefix_sum += nums[i] ;
         if( prefix_sum >= goal ){
            if( mp.find(prefix_sum-goal) != mp.end()){
                sub += mp[prefix_sum-goal] ; 
            }
         }
         mp[prefix_sum]++ ; 
        }
        return sub ; 
    }
};