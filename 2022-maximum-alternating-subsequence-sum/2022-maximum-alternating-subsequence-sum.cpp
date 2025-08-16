class Solution {
public:
    typedef long long ll ; 
    long long  t[1000001][2] ; 
    ll solve(vector<int>& nums,int idx ,bool flag ){
        int n = nums.size() ; 
        if( idx >= n ) return 0 ; 
        if( t[idx][flag] != -1 ) return t[idx][flag] ; 
        ll skip = solve(nums,idx+1,flag) ; 
        ll val= nums[idx] ;

        if( flag == false ){
            val = -val ; 
        }
        ll take =  solve(nums,idx+1,!flag) + val  ; 

        return t[idx][flag] = max(take,skip) ; 
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(t,-1,sizeof(t)) ; 
        return solve(nums,0,true) ; 
    }
};