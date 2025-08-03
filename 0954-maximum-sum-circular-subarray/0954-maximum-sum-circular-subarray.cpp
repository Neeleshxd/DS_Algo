class Solution {
  public:
    int kadanesmin(vector<int> &arr){
        int n = arr.size() ; 
        
        int min_element = arr[0] ; 
        int min_sofar = arr[0] ; 
        
        for( int i = 1 ;i < n ; i++ ){
            min_element = min(arr[i] , arr[i] + min_element ) ; 
            min_sofar = min(min_element,min_sofar ) ; 
        }
        return min_sofar ; 
    }
     int kadanesmax(vector<int> &arr){
        int n = arr.size() ; 
        
        int max_element = arr[0] ; 
        int max_sofar = arr[0] ; 
        
        for( int i = 1 ;i < n ; i++ ){
            max_element = max(arr[i] , arr[i] + max_element ) ; 
            max_sofar = max(max_element,max_sofar ) ; 
        }
        return max_sofar ; 
    }
    int maxSubarraySumCircular(vector<int> &arr) {
        // code here
        int sum = accumulate(arr.begin(),arr.end() , 0 ) ; 
        
        int min_sum = kadanesmin(arr) ; 
        int max_sum = kadanesmax(arr) ; 
        int circular_sum = sum - min_sum ; 
        
        return (max_sum > 0 ? max(max_sum,circular_sum) : max_sum ) ; 
    }
};
