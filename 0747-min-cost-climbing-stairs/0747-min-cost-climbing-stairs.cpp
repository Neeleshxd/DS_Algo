class Solution {
  public:
  int t[100001]; 
    int solve(int idx ,vector<int>& cost){
        if( idx >= cost.size()) return 0 ; 
        if( t[idx] !=  -1 ) return t[idx] ; 
        return t[idx] = cost[idx] + min(solve(idx+1,cost),solve(idx+2,cost)) ; 
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t,-1,sizeof(t)) ; 
        return min(solve(0,cost),solve(1,cost)) ; 
    }
};