class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size() ;
        int m = s.size() ; 
        int r = 0;
        int l = 0 ;
        
        sort(g.begin(),g.end()) ; 
        sort(s.begin(),s.end()) ; 
        while( r < n && l < m ){
          if( s[l] >= g[r]){
            r = r+1 ; 
          }
          l = l +1 ; 
        }
        return r ; 
    }
};