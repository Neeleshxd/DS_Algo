class Solution {
public:
    set<vector<int>>st ; 
    void solvethreesum(vector<int>& nums){
     int n = nums.size() ; 
    for( int i = 0 ; i < n-2 ; i++ ){
        int k = i+1 ; 
        int j = n-1; 
        while( k < j ){
        int sum = nums[i] + nums[j] + nums[k] ; 
        if( sum > 0  ){
            j--; 
        }else if(sum == 0){
            st.insert({nums[i],nums[j],nums[k]}) ; 
            k++;
        }else{
            k++; 
        }
        }
    }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ; 
        sort(nums.begin(),nums.end()) ; 
        solvethreesum(nums) ; 
        vector<vector<int>>result(st.begin(),st.end()) ;
        return  result ; 
    }
};