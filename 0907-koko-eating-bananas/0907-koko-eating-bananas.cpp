class Solution {
public:
    int possible(vector<int>& piles,int target ,int mid ){
        long long  time = 0 ; 
        for( int i = 0 ; i < piles.size() ; i++){
            time += (piles[i]+mid-1) / mid ; 
        }
        return(time<=target) ; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size() ; 
        long long low = 1 ; 
        long long high = *max_element(piles.begin(), piles.end()) ; 
        int ans = -1 ; 
        while( low <= high  ){
            int mid = low+(high-low)/ 2; 

            if( possible(piles,h,mid)){
                 ans = mid ; 
                 high = mid-1 ; 
            }else{
                low = mid +1 ; 
            }
        }
        return ans ; 
    } 
};