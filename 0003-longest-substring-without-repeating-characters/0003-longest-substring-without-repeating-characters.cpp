class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size() ; 
        unordered_map<char,int>mp ; 
        int i = 0;
        int j = 0;
         
        int max_sub = 0; 
        while( j < n ){
            mp[s[j]]++; //a , b ,c 
            while( mp[s[j]] > 1 ){
                mp[s[i]]--;// freq out 
                i++; //shrink the window 
            }
         max_sub = max(max_sub,j-i+1) ; 
         j++; 
        }
        return max_sub ; 
    }
};