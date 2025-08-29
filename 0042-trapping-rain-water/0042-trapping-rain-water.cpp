class Solution {
  public:
    void leftmax(vector<int>&left_max,vector<int> &arr){
        int n = left_max.size() ; 
        
        left_max[0] = arr[0] ; 
        
        for( int i = 1 ; i < n ;i++ ){
            left_max[i] = max(left_max[i-1],arr[i]) ; 
        }
    }
     void rightmax(vector<int>&right_max,vector<int> &arr){
        int n = right_max.size() ; 
        
        right_max[n-1] = arr[n-1] ; 
        
        for( int i = n-2 ; i >=0  ;i-- ){
            right_max[i] = max(right_max[i+1],arr[i]) ; 
        }
    }
    int trap(vector<int> &arr) {
        // code here
        int n =arr.size() ;
        
        vector<int>left_max(n,0) ;
        vector<int>right_max(n,0) ;
        
        leftmax(left_max,arr) ; 
        rightmax(right_max,arr) ; 
        
        int sum = 0 ; 
        for( int i = 0 ;i < n ; i++ ){
            
            int h = min(left_max[i],right_max[i]) - arr[i] ; 
            
            sum += h ; 
        }
        return sum ; 
    }
};