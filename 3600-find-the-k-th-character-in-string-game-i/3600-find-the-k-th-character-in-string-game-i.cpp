class Solution {
public:
     char mp(char c) {
    return (c == 'z') ? 'a' : c + 1;
}
    char kthCharacter(int k) {
        string str = "a" ; 
        while( str.size() < k ){
            string temp ="";
            for( char&ch : str ){
                temp += mp(ch) ; 
            }
            str += temp ;
        }
        return str[k-1];
    }
};