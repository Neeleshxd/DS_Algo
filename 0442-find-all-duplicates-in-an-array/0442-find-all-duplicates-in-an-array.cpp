class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp ;
        unordered_set<int>st ; 
        int n = nums.size() ;
        for( int x : nums ){
            mp[x]++; 
        } 
        for( int i = 0 ; i < n ; i++ ){
            if( mp[nums[i]] >= 2 ){
                st.insert(nums[i]) ; 
            }
        }
        vector<int>result(st.begin(),st.end()) ;

        return result ; 
    }
};