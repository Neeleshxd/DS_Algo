class Solution {
public:
    int day(vector<int>& weights,int capacity){
        long long  sum = 0 ;
        int days =1 ; 
        int n = weights.size() ; 
        for(int i = 0 ; i < n ; i++){
            sum += weights[i] ; 

            if( sum > capacity){
                days++;
                sum = weights[i] ;  
            } 
        }
        return days ; 
    }
    int shipWithinDays(vector<int>& weights, int days) {
        if( days > weights.size()) return -1;
        int l = *max_element(weights.begin() , weights.end()) ;
        int h = accumulate(weights.begin(),weights.end() , 0 ) ; 
        while( l <= h ){
            int mid = l +(h-l) / 2; 
            int maxdays = day(weights,mid) ; 
            if( maxdays > days){
                l = mid +1 ;  
            }else{
                h = mid -1  ; 
            }
        }
        return l ; 
    }
};