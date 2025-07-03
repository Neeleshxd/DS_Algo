class Solution {
public:
   
    char kthCharacter(int k) {
        unordered_map<char, char> mp = {
    {'a', 'b'}, {'b', 'c'}, {'c', 'd'}, {'d', 'e'}, {'e', 'f'},
    {'f', 'g'}, {'g', 'h'}, {'h', 'i'}, {'i', 'j'}, {'j', 'k'},
    {'k', 'l'}, {'l', 'm'}, {'m', 'n'}, {'n', 'o'}, {'o', 'p'},
    {'p', 'q'}, {'q', 'r'}, {'r', 's'}, {'s', 't'}, {'t', 'u'},
    {'u', 'v'}, {'v', 'w'}, {'w', 'x'}, {'x', 'y'}, {'y', 'z'},
    {'z', 'a'}
};

        string str = "a" ; 
        while( str.size() < k ){
            string temp ="";
            for( char&ch : str ){
                temp += mp[ch] ; 
            }
            str += temp ;
        }
        return str[k-1];
    }
};