class Solution {
  public:
  int t[1001][1001] ; 
    bool solve(string &s,int i , int j ){
        if( i >= j ) return 1 ; 
        if(t[i][j] != -1 ) return t[i][j] ; 
        if( s[i] == s[j]){
            return t[i][j] = solve(s,i+1,j-1) ; 
        }
        return t[i][j] = 0; 
    }
    string longestPalindrome(string &s) {
        // code here
        int sp = 0 ; 
        int n = s.size() ; 
        memset(t,-1,sizeof(t)) ; 
        int max_len = INT_MIN ; 
        for( int i = 0 ; i < n ;i++){
            for( int j = i ; j< n ; j++){
                if(solve(s,i,j) == true ){
                    if( max_len < j-i+1){
                        max_len = j-i+1; 
                        sp = i ; 
                    }
                }
            }
        }
        return s.substr(sp,max_len) ; 
        
    }
}; 