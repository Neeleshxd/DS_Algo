class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length() ;
        int count = 0 ; 
        unordered_map<char,int>mp;
        for(char&ch:s1){
            mp[ch]++;
        }
        int i = 0;
        int j = 0;
        while( j < s2.length()){
            if( mp.find(s2[j]) != mp.end()){
                mp[s2[j]]--;
                if(mp[s2[j]] >= 0 ){
                    count++; 
                }
            }
            while( j-i+1 > k ){
                if( mp.find(s2[i]) != mp.end()){
                    if(mp[s2[i]] >= 0 ){
                        count--; 
                    }
                    mp[s2[i]]++;
                }
                i++; 
            }
             if (j - i + 1 == k && count == k) {
                return true;
            }
            j++;
    }
    return false ; 
    }
};