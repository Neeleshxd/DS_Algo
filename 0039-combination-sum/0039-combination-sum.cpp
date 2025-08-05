class Solution {
public:
    vector<int>temp ;  
    vector<vector<int>>result ; 
    void solve(vector<int>& candidates,int target ,int idx){
        int n = candidates.size() ; 
        if( target == 0 ){
          result.push_back(temp) ;  
          return ; 
        }
        if( target < 0 ) return ; 
        for( int i = idx ; i < n ; i++ ){
            temp.push_back(candidates[i]) ; //do
            solve(candidates,target-candidates[i],i) ; // explore
            temp.pop_back() ; // undo  
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,target,0) ; 
        return result ; 
    }
};