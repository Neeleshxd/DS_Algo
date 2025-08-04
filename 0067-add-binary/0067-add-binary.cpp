// User function template for C++
class Solution {
  public:
    string trimleadingzeros(string &s ){
        size_t firstOne = s.find('1') ; 
        return (firstOne ==  string::npos)?"0" : s.substr(firstOne) ; 
    }
    string addBinary(string& s1, string& s2) {
        // your code here
        int carry = 0 ; 
        string ans="";
        s1 = trimleadingzeros(s1) ;
        s2 = trimleadingzeros(s2) ; 
       for(int i = 0; i< max(s1.size(),s2.size()) ; i++){
           int digitA = (i < s1.size()) ? s1[s1.size()-1-i] - '0' : 0 ; 
           int digitB = (i < s2.size()) ? s2[s2.size()-1-i] - '0' : 0 ;
           int sum = digitA +digitB +carry;
           char ch  = (sum % 2 ) +'0' ; 
           ans += ch ; 
           carry = sum / 2 ; 
       }
       
        if( carry){
            ans += '1'  ;  
        }
        reverse(ans.begin(),ans.end()) ; 
        return ans ; 
    }
};