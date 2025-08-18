class Solution {
  public:
  int t[1001][1001]  ; 
    bool isPalindrome(int i ,int j , string&s ){
        if( i >= j ) {
            return 1 ; }
        if( t[i][j] != -1 ) {
            return t[i][j] ;} 
        if( s[i] == s[j] )
            return t[i][j] = isPalindrome(i+1,j-1,s) ; 
        
            return t[i][j] = 0 ; 
    }
    string longestPalindrome(string &s) {
        int n = s.length() ;
         memset(t,-1,sizeof(t)) ; 
        int max_length =  1 ; 
        int start = 0; 
       for( int i = 0 ; i < n ; i++ ){
           for(int j = i ; j < n ; j++ ){
               if(isPalindrome(i,j,s)){
                   if( max_length < j-i+1 ){
                      max_length = max(max_length,j-i+1) ; 
                      start = i ; 
                   } 
               }
           }
       }
        return s.substr(start,max_length) ; 
    }
};
