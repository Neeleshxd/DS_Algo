class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int n = nums.size() ; 
       int max_sub =  0 ;
       int i = 0;
       int j = 0;
       int count_zero = 0;
       int flipping_range = 0;
       if( k == 0 ){
         j = 0 ; 
         while( j < n ){
            if( nums[i] == 1 && nums[j] == 1 ){
                max_sub = max(max_sub,j-i+1) ; 
            }else{
                i = j ; 
            }
            j++; 
         }
       }else{
        while( j < n ){
        if( nums[j] == 0 ) count_zero++ ; 
        flipping_range = k - count_zero ; 
        while( flipping_range < 0 && i < j ){
            if( nums[i] == 0 ){
                flipping_range += 1 ; 
                count_zero-- ; 
            }
            i++; 
        }
        max_sub = max(max_sub,j-i+1) ; 
        j++; 
       }
       }
       return max_sub ;  
    }
};