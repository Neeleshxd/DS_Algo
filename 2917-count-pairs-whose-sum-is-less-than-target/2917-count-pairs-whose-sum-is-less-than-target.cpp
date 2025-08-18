class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int n = arr.size() ; 
        int i = 0 ;
        int j = n-1 ;
        int count = 0 ;
        sort(arr.begin(),arr.end()) ; 
        while( i < j ){
            
            if( arr[i] + arr[j] >= target ) j--; 
            if( arr[i] + arr[j] < target ){
                count += j-i ; 
                i++; 
            }
        }
        return count ; 
    }
};
