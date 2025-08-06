class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() ; 
        int h = n-1 ; 
        int l = 0 ;
        int mid = 0 ;

        while( mid <= h ){
            if( nums[mid] == 0 ){
              swap(nums[mid],nums[l]) ; 
              l++;
              mid++; 
            }else if(nums[mid] == 1 ){
              mid++; 
            }else{
               swap(nums[mid],nums[h]) ; 
               h--; 
            }
        }
    }
};