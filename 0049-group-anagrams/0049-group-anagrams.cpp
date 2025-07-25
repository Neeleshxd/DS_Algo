class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size() ; 
        unordered_map<string,vector<string>>mp ; 
        vector<vector<string>>result  ; 
       for( string word : strs ){
           string sorted_word = word ;
           sort(sorted_word.begin() , sorted_word.end()) ; 
           mp[sorted_word].push_back(word) ; 
       }
       for(auto&it:mp ){
          result.push_back(it.second) ; 
       }
       return result ; 
    }
};