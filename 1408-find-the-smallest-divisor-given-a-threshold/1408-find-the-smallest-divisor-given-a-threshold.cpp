class Solution {
public:
    int threshold_range(vector<int> nums,int t,int mid  ){ 
        for( int i = 0 ; i < nums.size() ; i++ ){
            nums[i] = (nums[i] + mid - 1 ) / mid ; 
        }
        int sum = accumulate(nums.begin(),nums.end(),0) ; 
        return sum ; 
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size() ;
        int l = 1;
        int h = *max_element(nums.begin(),nums.end()) ; 
        int ans = -1 ; 
        while( l <= h ){
         int mid = l+(h-l) / 2 ; 

         if( threshold_range(nums,threshold,mid) <= threshold){
             ans = mid ; 
             h = mid - 1 ;
         }else{
            l = mid + 1; 
         }
        }
        return ans ; 
    }
};