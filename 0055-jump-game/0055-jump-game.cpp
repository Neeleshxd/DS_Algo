class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ; 
        if( n <= 1 ) return true ; 
        if(nums[0] == 0 ) return false ; 
        
        int curr_end  = 0 ; 
        int max_dist = 0 ; 
        for( int i = 0; i < n ; i++ ){
           max_dist = max(max_dist ,nums[i]+i) ; 

           if( i == curr_end){
            curr_end = max_dist  ; 
            if( curr_end >= n-1 ) return true ; 
           }
        }
        return false ; 
    }
};