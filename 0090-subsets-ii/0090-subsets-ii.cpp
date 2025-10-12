class Solution {
public:
    void solve(vector<int>& nums,int idx ,set<vector<int>>&st,vector<int>&temp){
        int n = nums.size() ; 
        if( idx >= n ){
            st.insert(temp) ; 
            return ; 
        }
        temp.push_back(nums[idx]) ; 
        solve(nums,idx+1,st,temp) ; 
        temp.pop_back() ; 
        solve(nums,idx+1,st,temp) ;  
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st ; 
        vector<int>temp ; 
        sort(nums.begin(),nums.end()) ; 
        solve(nums,0,st,temp) ;
        return vector<vector<int>>(st.begin(),st.end()) ;   
    }
};