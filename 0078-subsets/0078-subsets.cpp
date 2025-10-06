class Solution {
public:
   void solve(int idx ,vector<int>& nums, vector<vector<int>>&result,vector<int>&temp ){
    int n = nums.size() ; 
    if( idx >= n ){
        result.push_back(temp) ; 
        return ; 
    }
    temp.push_back(nums[idx]) ; 
    solve(idx+1,nums,result,temp) ; 
    temp.pop_back() ;
    solve(idx+1,nums,result,temp) ;  
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result ; 
        vector<int>temp ; 
        solve(0,nums,result,temp) ; 
        return result ; 
    }
};