class Solution {
public:
    bool isvowel(char c ){
        return (c == 'a' || c == 'e' || c =='i' || c =='o' || c=='u') ; 
    }
    int maxFreqSum(string s) {
        int n = s.size() ; 
        vector<int>mp(26,0);  

        for(char ch : s ){
            mp[ch-'a']++; 
        }
        int max_vowel = 0 ;
        int max_consonants = 0 ; 
        for( char x : s  ){
            if( isvowel(x)){
             max_vowel = max(max_vowel,mp[x-'a']) ; 
            }else{
                max_consonants = max(max_consonants,mp[x-'a']) ; 
            }
        }
        return max_vowel + max_consonants ;  
    }
};