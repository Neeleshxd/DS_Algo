class Solution {
public:
int t[2501][2501] ; 
int solve(vector<int>& nums,int idx ,int p ){
    int n = nums.size() ; 
    if( idx >= n ) return 0 ;
    if( p != -1 && t[idx][p] != -1 ) return t[idx][p] ; 
    int take = 0 ;  
    if( p == -1 || nums[p] < nums[idx]){
         take = 1 + solve(nums,idx+1,idx) ; 
    }
    int skip = solve(nums,idx+1,p) ; 
    return ((p != -1 )?t[idx][p] = max(take,skip):max(take,skip)) ; 
}
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t)) ; 
        return solve(nums,0,-1) ; 
    }
};