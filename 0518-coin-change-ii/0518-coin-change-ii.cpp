class Solution {
  public:
    int t[305][5005] ; 
    int solve(vector<int>& coins, int target , int sum,int idx  ){
        int n = coins.size() ; 
        if( sum == target ) return 1 ;
        if( sum > target ) return 0 ; 
        if( t[idx][sum] != -1 ) return t[idx][sum] ; 
        int ways = 0; 
        for( int i = idx ; i < n ; i++ ){
           ways +=  solve(coins,target,sum+coins[i],i) ; 
        }
        return t[idx][sum] = ways ; 
    }
    int change(int sum ,vector<int>& coins) {
      memset(t,-1,sizeof(t)) ; 
      return solve(coins,sum,0,0) ; 
    }
};