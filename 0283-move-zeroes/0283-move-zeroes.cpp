class Solution {
  public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size(); 
        
        int start = 0 ; 
        for( int end = 0 ; end < n ; end++){
            
            if( arr[start] == 0 && arr[end] != 0 ){
                swap(arr[start],arr[end]) ; 
            }
            if( arr[start] != 0 )start++; 
        }
    }
};