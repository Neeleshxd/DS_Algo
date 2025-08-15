class Solution {
public:
    int t[101] ; 
    int solve(vector<int>& nums,int idx ){
        int n = nums.size() ; 
        if( idx >= n ) return 0 ;
        if( t[idx] != -1 ) return t[idx] ; 
        int take = nums[idx] + solve(nums,idx+2) ; 
        int nottake  = solve(nums,idx+1) ; 
        int ans =  max(take,nottake) ;  
        return t[idx] = ans ; 
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ; 
         memset(t,-1,sizeof(t)) ;
        int max_rob = solve(nums,0) ;  
        return max_rob ; 
    }
};