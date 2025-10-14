class Solution {
public:
    bool isValid(string s) {
        stack<char>st ; 
        int n = s.size() ; 
        for( int i = 0 ; i < n ; i++){
            char ch = s[i] ; 
            if( !st.empty() && ch == ')'&& st.top() == '('){
                st.pop() ; 
            }else if(!st.empty() &&ch == ']'&& st.top() == '['){
                st.pop() ; 
            }else if(!st.empty() &&ch == '}'&& st.top() == '{'){
                st.pop() ; 
            }else{
                st.push(ch) ; 
            }
        }
        return (st.empty()) ; 
    }
};