class Solution {
public:
    void solve(string digits,int idx , unordered_map<char,string>&ch,string temp,vector<string>&result){
        int n = digits.size() ; 
        if( idx >= n ){
            result.push_back(temp) ; 
            return; 
        }
        char c = digits[idx] ; 
        string str = ch[c] ; // 2 <--> abc 
        for( int i = 0 ; i < str.length() ; i++){
           temp.push_back(str[i]) ; 
           solve(digits,idx+1,ch,temp,result) ; 
           temp.pop_back() ; 
        }
    }
    vector<string> letterCombinations(string digits) {
        string temp = "" ; 
        vector<string>result ; 
        unordered_map<char,string>ch ; 
        ch['2'] = "abc" ; 
        ch['3'] = "def" ; 
        ch['4'] = "ghi" ; 
        ch['5'] = "jkl" ; 
        ch['6'] = "mno" ; 
        ch['7'] = "pqrs" ; 
        ch['8'] = "tuv" ; 
        ch['9'] = "wxyz" ; 
        if(digits.size() == 0 ) return {} ; 
        solve(digits,0,ch,temp,result) ; 
        return result ;
    }
};