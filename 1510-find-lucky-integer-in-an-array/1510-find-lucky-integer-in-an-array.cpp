class Solution {
public:
    int findLucky(vector<int>& arr) {
        int m = 501 ; 
        vector<int>mp(m,0) ; 
        int n = arr.size() ;
        for( int& x : arr ){
            mp[x]++; 
        }
        int ans = -1 ; 
        for( int i = 0 ; i < n ; i++){
           if(mp[arr[i]] == arr[i]){
             ans = max(arr[i],ans) ; 
           }
        }
        return ans ; 
    }
};