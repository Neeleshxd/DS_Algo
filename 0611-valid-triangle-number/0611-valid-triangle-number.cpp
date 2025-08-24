class Solution {
  public:
    int triangleNumber(vector<int>& arr) {
        // code here
        int n = arr.size() ;
        sort(arr.begin(),arr.end()) ; 
        
        int count = 0 ; 
        for( int k = n-1 ; k >= 2 ; k--){
            int i = 0;
            int j = k-1 ; 
            while( i < j ){
                if(arr[i] + arr[j] > arr[k]){
                    count += j-i ; 
                    j--; 
                }else{
                    i++; 
                }
            }
        }
        return count ; 
    }
};
