class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size() ; 
        unordered_map<int,int>mp; 
        for( int &x : nums){
            mp[x]++; 
        }
        vector<vector<int>>bucket(n+1) ; 
        for(auto&it:mp ){
            int first_element = it.first ; 
            int second_element = it.second ; 
            bucket[second_element].push_back(first_element) ; 
        }
        vector<int>result ; 
        for( int i = n ; i >= 0 ; i-- ){
           if( bucket[i].size() == 0 ) continue ; 
           while( bucket[i].size() > 0 && k > 0 ){
              result.push_back(bucket[i].back()) ; 
              bucket[i].pop_back() ; 
              k--; 
           }
        }
        return result ; 
    }
};