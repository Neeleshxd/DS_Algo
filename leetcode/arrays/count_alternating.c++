//Brute Force
class Solution {
public:
long long countAlternatingSubarrays(vector<int>& nums) {
    long long sub = 0 ;
    int n = nums.size();

    for( int i = 0 ; i < n ; i++ ){
    for( int j = i ; j < n ; j++ ){
       
        if(  j > i && nums[j] == nums[j-1] ){
            break ; 
        }
        sub++;
    }
    }
    return sub ; 
}
};//Tc O(N^2) SC O(1)
//Optimal 1
class Solution {
    public:
        long long countAlternatingSubarrays(vector<int>& nums) {
            int n = nums.size() ;
            long long sub = 0 ;  
            int  count = 1 ;
    
            for( int i = 0 ; i < n ; i++ ){
    
            if( i > 0 && nums[i] != nums[i-1]){
            count++; 
            }else{
            count = 1 ;
            } 
            sub += count ; 
            }
            return sub ; 
        }
    }; //Tc O(N) SC O(1)
//Optimal 2
class Solution {
    public:
        long long countAlternatingSubarrays(vector<int>& nums) {
            int n = nums.size() ;
            long long sub = 0 ;
    
            for( int i = 0 ; i < n ; i++ ){
            int j = i ; 
            while( j+1 < n &&  nums[j] != nums[j+1] ){
                j++;
            }
            int len = j - i + 1 ;
            sub += (long long )len*(len+1)/2 ; 
            i = j ; 
            }
            return sub ; 
        }
    }; //Tc O(N) SC O(1)