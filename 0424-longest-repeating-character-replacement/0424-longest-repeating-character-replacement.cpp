class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp ; 
        int i = 0;
        int j = 0 ; 
        int n = s.size() ; 
        int max_freq = 0 ; 
        int max_sub = 0 ; 
        while( j < n ){
            mp[s[j]]++;
            max_freq = max(mp[s[j]],max_freq) ; 

            while( (j-i+1)-max_freq > k ){
                mp[s[i]]--;
                i++; 
            }
            max_sub = max(max_sub,j-i+1) ;
            j++; 
        }
        return max_sub ; 
    }
};