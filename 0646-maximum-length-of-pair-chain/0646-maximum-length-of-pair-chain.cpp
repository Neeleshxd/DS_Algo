class Solution {
public:
    int t[1001][1001] ; 
    int solve(vector<vector<int>>& pairs,int idx , int b ){
        int n = pairs.size() ;
        if( idx >= n ) return 0 ;
        if(b != -1 && t[idx][b] != -1 ) return t[idx][b] ;  
        int take = 0 ; 
        if( b == -1 || pairs[idx][0] > pairs[b][1]){
            take = 1 + solve(pairs,idx+1,idx) ; 
        }
        int skip = solve(pairs,idx+1,b) ; 

        return ( b != -1 ? t[idx][b]=max(take,skip) : max(take,skip)) ; 
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end()) ; 
        memset(t,-1,sizeof(t)) ; 
        return solve(pairs,0,-1) ; 
    }
};