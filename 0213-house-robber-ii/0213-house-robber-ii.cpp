class Solution {
public:
    int t[101] ; 
    int solve(vector<int>& nums,int idx ,int s ){
        if( idx >= s ) return 0 ; 
        if( t[idx] != -1 ) return t[idx] ; 
        int take = nums[idx]+solve(nums,idx+2,s) ;
        int nottake = solve(nums,idx+1,s) ; 
        int ans = max(take,nottake) ; 
        return t[idx] = ans ; 
    }
    int rob(vector<int>& nums) {
        int n =nums.size() ; 
        if( n == 1 ) return nums[0] ;
        if( n ==2 ) return max(nums[0],nums[1]) ; 

        memset(t,-1,sizeof(t)) ;  
        int ans = solve(nums,0,n-1) ; 
        memset(t,-1,sizeof(t)) ; 
        int ans2 = solve(nums,1,n) ; 

        return max(ans,ans2) ; 
    }
};