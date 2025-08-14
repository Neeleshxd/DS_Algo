class Solution {
public:
    set<vector<int>>st ; 
    vector<int>temp ; 
    void solve(vector<int>& nums,int idx ){
        int n = nums.size() ; 
        if( idx >= n ){
          st.insert(temp) ; 
          return ; 
        }
        temp.push_back(nums[idx]) ; 
        solve(nums,idx+1) ; 
        temp.pop_back() ;
        solve(nums,idx+1) ; 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ; 
        solve(nums, 0) ;
        vector<vector<int>>result(st.begin(),st.end()) ;  
        return result ; 
    }
};