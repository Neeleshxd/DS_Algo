class Solution {
public:
    int makeBoquet(vector<int>&bloomDay,int mid ,int  k ){
        int n = bloomDay.size() ; 
        int count = 0 ; 
        int boquets = 0 ;
        for( int i = 0 ; i< n ; i++ ){
            if( bloomDay[i] <= mid ){
             count++; 
            }else{
                count = 0; 
            }
            if( count == k ){
              boquets++ ; 
              count = 0; 
            }
        }
        return boquets ; 
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
      int l = 0 ;
      int h = *max_element(bloomDay.begin(),bloomDay.end()) ; 
      int min_days = -1 ; 
      while( l <= h ){
        int mid = l +(h-l) / 2 ; 

        if( makeBoquet(bloomDay,mid,k)>= m ){
            min_days = mid ; 
            h = mid -1 ;
        }else{
            l = mid +1 ; 
        }
      }
      return min_days ;    
    }
};