class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size() ; 
        unordered_map<int,int>mp;
        for( int& m : nums ){
            mp[m]++; 
        }
        for( int i = 1 ; i <= n ; i++ ){
            if(mp.find(i) == mp.end()){
                return i ;
                break ; 
            }
        }
        return n+1 ;  
    }
};