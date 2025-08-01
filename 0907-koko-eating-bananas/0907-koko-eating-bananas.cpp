class Solution {
public:
    bool caneat(vector<int>&piles,int mid ,int h ){
        int actual_hours = 0 ; 
        for( int & x : piles ){
            actual_hours += x / mid ; 
            if( x % mid != 0 ){
                actual_hours++ ; 
            }
        }
        return actual_hours <= h ; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size() ; 
        int l = 1 ; 
        int r = *max_element(piles.begin(),piles.end()) ; 

        while( l < r ){
            int mid = l +(r-l) / 2 ; 

            if(caneat(piles,mid,h)){
                r = mid ; 
            }else{
                l = mid +1 ; 
            }
        }
        return l ; 
    }
};