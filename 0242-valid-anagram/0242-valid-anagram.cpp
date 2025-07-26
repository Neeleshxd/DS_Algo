class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size() ; 
        unordered_map<char,int>mp ; 
         if( n < t.size()) return false ; 
        for( char&ch : s ){
            mp[ch]++; 
        }
        int i = 0;
        int j = 0;
        int count = 0 ; 
        while( j < t.size()){
          if( mp[t[j]] > 0 ){
            count++; 
            mp[t[j]]--; 
          }

          while( i < j && (j-i+1) > n  ){
            if( mp.find(t[i]) != mp.end()){
                count--; 
                mp[t[i]]++;
            }
            i++; 
          }
          if( count == n && j-i+1 == n ){
            return true ; 
          }
          j++; 
        }
        return false ; 
    }
};