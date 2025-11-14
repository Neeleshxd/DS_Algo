class Solution {
  public:
    int n ;
    vector<vector<int>>dp ; 
    int solve(string&s ,int i ,int j ){
        if( i >= j ) return true ; 
        if(dp[i][j] != -1)return dp[i][j]; 
        if( s[i] == s[j]){
            return dp[i][j] = solve(s,i+1,j-1) ; 
        }
        return false ; 
    }
    int countSubstrings(string &s) {
        // code here
         n = s.size() ; 
        dp.assign(n,vector<int>(n,-1)); 
        int count = 0 ; 
        for ( int i = 0 ; i < n ; i++ ){
            for( int j = i ; j < n ; j++){
                if( solve(s,i,j)){
                    count++; 
                }
            }
        }
        return count ; 
    }
};