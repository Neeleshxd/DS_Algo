class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ; 
        if( n == 0 ) return 0 ; 
        sort(nums.begin(),nums.end()) ; 
        int smallest = INT_MIN ;
        int  cnt = 0 ; 
        int longest = 1 ; 
        for( int i = 0 ; i < n ; i++ ){
            if( nums[i]- 1 == smallest ){
                cnt += 1 ; 
                smallest = nums[i] ; 
            }else if(smallest != nums[i]){
                cnt = 1 ;
                smallest = nums[i] ; 
            }
            longest = max(longest,cnt) ; 
        }
        return longest ; 
    }
};