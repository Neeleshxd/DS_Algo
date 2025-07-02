class Solution
{
    public: 
        vector<vector<int>>result ; 
        vector<int>temp ; 
        void solve(vector<int> &nums,int idx ){
            int n = nums.size() ; 
                result.push_back(temp) ;
            for( int i = idx ; i < n ; i++ ){
                if( i > idx && nums[i] == nums[i-1]) continue ; 
                temp.push_back(nums[i]) ;
                solve(nums,i+1) ; 
                temp.pop_back() ; 
            }
        }
        vector<vector < int>> subsetsWithDup(vector<int> &nums) {
            sort(nums.begin(),nums.end()) ; 
            solve(nums,0) ; 
            return result;  
        }
};