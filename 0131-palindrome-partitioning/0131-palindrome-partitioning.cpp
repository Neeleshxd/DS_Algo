class Solution {
public:
    int n ; 
    bool isPalindrome(string s ,int l,int r ){
        while( l < r ){
            if( s[l] != s[r]) return false ; 
            l++;
            r--;
        }
        return true ; 
    }
    void backtrack(string s , int idx , vector<string>&temp,vector<vector<string>>&result){
        if( idx == n ){
            result.push_back(temp) ; 
            return ; 
        }
        for( int i = idx ; i < n ;i++ ){
            if( isPalindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1)) ; 
                backtrack(s,i+1,temp,result) ; 
                temp.pop_back() ; 
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size() ; 
        vector<vector<string>>result ; 
        vector<string>temp ; 
        backtrack(s,0,temp,result) ; 
        return result ;
    }
};