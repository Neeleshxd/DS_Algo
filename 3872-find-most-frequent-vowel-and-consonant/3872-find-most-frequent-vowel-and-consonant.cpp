class Solution {
public:
    bool isvowel(char c ){
        return (c == 'a' || c == 'e' || c =='i' || c =='o' || c=='u') ; 
    }
    int maxFreqSum(string s) {
        int n = s.size() ; 
        unordered_map<char,int>mp ; 

        for(char ch : s ){
            mp[ch]++; 
        }
        int max_vowel = 0 ;
        int max_consonants = 0 ; 
        for( int i = 0 ;i < n ; i++ ){
            if( isvowel(s[i])){
             max_vowel = max(max_vowel,mp[s[i]]) ; 
            }else{
                max_consonants = max(max_consonants,mp[s[i]]) ; 
            }
        }
        return max_vowel + max_consonants ;  
    }
};