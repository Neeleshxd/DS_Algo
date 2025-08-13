class Solution {
public:
    set<vector<int>>st; 
    void solve(vector<int>& nums,int idx ){
        int n = nums.size() ; 
        if( idx == n ){
          st.insert(nums) ; 
          return ; 
        }
        for( int i = idx ; i < n ; i++ ){
            swap(nums[i],nums[idx]) ; 
            solve(nums,idx+1) ; 
            swap(nums[i],nums[idx]) ; 
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0) ; 
         vector<vector<int>>result(st.begin(),st.end()) ;
         return result ;  
    }
};