class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if( numerator == 0 ) return "0" ;
        string result ; 

        if( (long long)numerator * (long long)denominator < 0 ) {
          result += "-" ; 
        }

        long long absnums =  labs(numerator) ; 
        long long absdeno = labs(denominator) ; 
        
        long long integerdiv = absnums / absdeno ; 

        result += to_string(integerdiv) ; 

        long long remain =  absnums % absdeno ;

        if( remain == 0 ){
            return result ; 
        } 
        result += '.' ; 

        unordered_map<int,int>mp ; 

        while( remain != 0 ){
            if( mp.find(remain) != mp.end()){
                result.insert(mp[remain],"(") ; 
                result += ")" ; 
                break ; 
            }
            mp[remain] = result.length() ; 
            remain *= 10 ; 
            int digit = remain / absdeno ; 
            result += to_string(digit) ; 
            remain = (remain % absdeno) ; 
        }
        return result ; 
    }
};