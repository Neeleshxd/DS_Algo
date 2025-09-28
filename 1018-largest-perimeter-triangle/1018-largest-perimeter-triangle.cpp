class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size() ; 

        int max_perimeter = 0 ; 
       sort(nums.begin(),nums.end()); 
       for( int k = n-1 ; k >= 2 ; k-- ){
           int j = k-1 ; 
           int i = j-1 ;
           while( i < j ){
            if( nums[i] + nums[j] > nums[k] ){
               max_perimeter = nums[i]+nums[j]+nums[k] ;  
               return max_perimeter ; 
            }
                i++;            
           }
       }
       return max_perimeter ; 
    }
};