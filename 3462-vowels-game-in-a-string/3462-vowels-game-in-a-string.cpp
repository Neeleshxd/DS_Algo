class Solution {
public:
    bool isvowel(char ch ){
        if(ch == 'a'||ch == 'e' || ch == 'i'|| ch == 'o'||ch=='u'){
            return true ;
        }
        return false ;
    }
    bool doesAliceWin(string s) {
        int n = s.size() ;
        int count_vowels = 0 ; 
        for( char x : s ){
            if(isvowel(x)){
                count_vowels++; 
            }
        }
        if( count_vowels == 0 ) return false ; 
        return true ; 
    }
};