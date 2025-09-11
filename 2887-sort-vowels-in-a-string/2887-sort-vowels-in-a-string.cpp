class Solution {
public:
    bool isvowel(char c ){
        if( c == 'a' || c == 'A' || c == 'e'||c == 'E'||c == 'I'||c == 'i'||c == 'o'||c == 'O'||c == 'u'||c == 'U' ){
            return true ; 
        }
        return false ;
    }
    string sortVowels(string s) {
        int n = s.size() ; 
        vector<int>ascii ; 
        for( char ch : s ){
            if(isvowel(ch)){
              ascii.push_back((int)ch) ; 
            }
        }
        if( !ascii.size()) return s ; 
        sort(ascii.begin(),ascii.end()) ; 
        int i = 0;
        int start = 0 ; 
        while( i < n ){
            if( isvowel(s[i])){
                s[i] = (char)ascii[start] ; 
                start++; 
            }
            i++; 
        }
        return s ; 
    }
};