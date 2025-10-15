class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size() ; 
        stack<int>st ; 
        for(int i = 0 ; i < n ; i++ ){
            string ch = tokens[i] ; 
            if( !st.empty()&& ch == "+"){
                int a = st.top();st.pop() ; 
                int b = st.top();st.pop() ; 
                int ans = a + b ; 
                st.push(ans) ; 
            }else if(!st.empty()&& ch == "-"){
                int a = st.top();st.pop() ; 
                int b = st.top();st.pop() ;
                int ans = b - a  ; 
                st.push(ans) ; 
            }else if(!st.empty()&& ch == "*"){
                int a = st.top();st.pop() ; 
                int b = st.top();st.pop() ; 
                int ans = a * b ; 
                st.push(ans) ;
        }else if(!st.empty()&& ch == "/"){
                int a = st.top();st.pop() ; 
                int b = st.top();st.pop() ;
                int ans = b /a  ;  
                st.push(ans) ;}
        else{
            st.push(stoi(ch)) ; 
        }
    }
     return st.top(); 
    }
};