class Solution {
public:
   bool iszero(int a ){
    int x = a ;

    while( x > 0 ){
        if( x % 10 == 0 ) return true ; 
        x /= 10 ; 
    }
    return false ; 
   }
    vector<int> getNoZeroIntegers(int n) {
        for( int a = 1 ; a < n ; a++ ){
            int b = n -a ; 

            while( !iszero(a) && !iszero(b)){
                return {a,b} ; 
            }
        }
        return {} ;  
    }
};