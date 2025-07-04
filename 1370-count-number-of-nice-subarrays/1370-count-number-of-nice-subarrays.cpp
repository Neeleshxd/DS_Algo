class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size() ;
        int i = 0 ;
        int j = 0 ;
        int prev_count = 0;
        int sub_count = 0;
        int odd_count = 0;
        while( j < n ){
            if( nums[j] % 2 == 1){
                odd_count++;
                prev_count = 0;
            }
            while( i < n && odd_count == k ){
                prev_count++ ;
                if( nums[i] % 2 == 1 ){
                    odd_count--; 
                }
                i++; 
            }
                sub_count += prev_count ; 
            j++ ; 
        }
        return sub_count ; 
    }
};