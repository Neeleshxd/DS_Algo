class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size() ; 
        int l = 0 ;
        int h = n-1 ; 
        while( l <= h ){
          int mid = l+(h-l) / 2 ; 
          if(nums[mid] == target ) return true  ; 
          if( nums[l] == nums[mid]&& nums[mid] == nums[h]){
            l++; 
            h--;
            continue ; 
          }
          if( nums[l] <= nums[mid]){
            if( nums[l]<= target &&  nums[mid] >= target ){
                h = mid -1 ; 
            }else{
                l = mid +1 ; 
            }
          }else if(nums[l] > nums[mid]){
            if(  nums[mid] <= target && nums[h] >= target ){
                l = mid +1 ; 
            }else{
                h = mid -1 ; 
            }
          }
        }
        return false  ; 
    }
};