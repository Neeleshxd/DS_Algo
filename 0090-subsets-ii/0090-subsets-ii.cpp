class Solution
{
    public: 
        vector<int>temp ;
        set<vector<int>>st ; 
        void solve(vector<int> &nums,int idx ){
            int n = nums.size() ; 
            if( idx == n ){
                st.insert(temp) ;
                return ; 
            }
            if( idx < n ){
                temp.push_back(nums[idx]) ;
            }
            solve(nums,idx+1) ; 
            temp.pop_back() ;
            solve(nums,idx+1) ; 
        }
        vector<vector < int>> subsetsWithDup(vector<int> &nums) {
            sort(nums.begin(),nums.end()) ; 
            solve(nums,0) ; 
            return vector<vector<int>>(st.begin(),st.end()) ; 
        }
};