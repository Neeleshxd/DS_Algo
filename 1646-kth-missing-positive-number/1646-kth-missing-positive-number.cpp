class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>mp ;
        for(int x : arr ){
            mp[x]++; 
        }
        int n = arr.size() ; 
        int count = 0; 
        int max_num = *max_element(arr.begin(),arr.end()) ; 
        for( int i = 1 ; i <= max_num + k  ; i++ ){
            if( mp.find(i) == mp.end()){
                count++; 
            }
            if( count ==  k ){
                return i ; 
                break ; 
            }
        }
        return -1 ; 
    }
};