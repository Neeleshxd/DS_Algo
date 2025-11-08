;
class Solution {
  public:
  int t[1001][1001] ; 
    static bool myFunction(string&word1,string&word2){
        return word1.length() < word2.length(); 
    }
    bool ispredecessor(string&word1 , string&word2){
        int n = word1.length() ; 
        int m = word2.length() ;
        if( n >= m || (m-n) != 1 ) return false ; 
        
        int i = 0 ;
        int j = 0 ;
        
        while( i < n && j < m ){
            if( word1[i] == word2[j]){
                i++;
            }
            j++; 
        }
        return i == n ; 
    }
    int solve(vector<string>& words,int idx ,int prev_idx){
        int n = words.size() ; 
        if( idx == n ) return 0 ; 
        int take = 0  ;
        if( prev_idx != -1 && t[idx][prev_idx] != -1 ) return t[idx][prev_idx] ; 
        if( prev_idx == -1 || ispredecessor(words[prev_idx],words[idx])){
            take = 1+ solve(words,idx+1,idx) ; 
        } 
        
         int not_take =  solve(words,idx+1,prev_idx) ; 
         
         return (prev_idx != -1 ? t[idx][prev_idx] = max(take,not_take):max(take,not_take)) ; 
    }
    int longestStrChain(vector<string>& words) {

        memset(t,-1,sizeof(t)) ; 
        sort(words.begin(),words.end(),myFunction) ; 
        return solve(words,0,-1) ; 
    }
};