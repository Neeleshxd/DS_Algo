class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size() ; 
        int i = 0;
        int j = 0;
        long long product = 1 ; 
        int sub_count = 0 ; 
        if( k == 0 ) return 0 ; 
        while( j < n ){
         product *= nums[j] ; 

         while( i < j  && product >= k ){
            product = (long long)product / nums[i] ; 
            i++; 
         }
         if( product < k ){
         sub_count += j-i+1;
         } 
         j++; 
        }
        return sub_count ; 
    }
};