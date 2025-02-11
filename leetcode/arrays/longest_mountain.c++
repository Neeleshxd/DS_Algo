class Solution {
    public:
        int longestMountain(vector<int>& arr) {
            int n = arr.size() ;
            int mid =1 ;
            int max_mountain = 0 ;
            if( n < 3 ) return 0 ; 
            while( mid < n-1 ){
                if( arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1] ){
                    int start = mid-1;
                    int end = mid+1;
                
                while( start > 0 && arr[start] > arr[start-1]){
                 start--;
                }
                while( end < n-1 && arr[end] > arr[end+1]){
                end++;
                }
                max_mountain = max(max_mountain,end-start+1) ; 
                }
                mid++;
            }
            return max_mountain ; 
        }
    };//TC: O(n) SC: O(1) where n is the size of the array