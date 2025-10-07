class Solution {
public:
    void solve(vector<int>& candidates,vector<int>&temp,vector<vector<int>>&result,int target ,int sum ,int idx ){
        int n = candidates.size() ; 
        if( sum > target ) return ; 
        if( sum == target ){
            result.push_back(temp) ; 
            return ; 
        }
        for( int i = idx ; i < n ; i++ ){
            temp.push_back(candidates[i]) ; 
            solve(candidates,temp,result,target,sum+candidates[i],i) ; 
            temp.pop_back() ; 
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp ; 
        vector<vector<int>>result ;
        solve(candidates,temp,result,target,0,0) ; 
        return result ; 
    }
};