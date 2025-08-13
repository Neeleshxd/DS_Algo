class Solution {
public:
    vector<vector<int>>result ; 
    vector<int>temp ; 
    void solve( vector<int>& nums,int idx ){
        int n = nums.size() ; 
        if( idx >= n ){
            result.push_back(temp) ; 
            return ; 
        }
        temp.push_back(nums[idx]) ; 
        solve(nums,idx+1) ;

        temp.pop_back() ; 
        solve(nums,idx+1) ; 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0) ;
        return result ;  
    }
};