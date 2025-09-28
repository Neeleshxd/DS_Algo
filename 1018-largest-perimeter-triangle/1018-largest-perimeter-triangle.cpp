class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size() ; 

        int max_perimeter = 0 ; 
       sort(nums.begin(),nums.end()); 
       for( int k = n-1 ; k >= 2 ; k-- ){
           int i = 0 ;
           int j = k-1 ; 
           while( i < j ){
            if( nums[i] + nums[j] > nums[k] ){
                max_perimeter = max(max_perimeter,nums[i]+nums[j]+nums[k]) ; 
            }
                i++;            
           }
       }
       return max_perimeter ; 
    }
};