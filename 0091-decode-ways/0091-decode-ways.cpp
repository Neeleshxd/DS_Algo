 int t[101] ; 
class Solution {
  public:
    int solve(string &digits,int idx , int n ){
        if( idx == n ) return 1 ; 
        
        if(t[idx] != -1 ) return t[idx] ; 
        if(digits[idx] == '0') return 0 ; 
        int result = solve(digits,idx+1,n) ; 
        if( idx+1 < n ){
         if( digits[idx] == '1' || (digits[idx] == '2' && digits[idx+1] <= '6')){
            result += solve(digits,idx+2,n) ; 
        }   
        }
        return t[idx] = result ; 
    }
    int numDecodings(string &digits) {
        int n = digits.size() ; 
        memset(t,-1,sizeof(t)) ; 
        return solve(digits,0,n) ; 
    }
};