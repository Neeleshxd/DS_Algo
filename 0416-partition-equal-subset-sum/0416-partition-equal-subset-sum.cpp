class Solution {
  public:
   int t[201][20001];
   bool solve(vector<int>& arr,int target ,int idx ,int sum ){
       int n = arr.size() ; 
       if(t[idx][sum] != -1 ) return t[idx][sum] ; 
       if( sum == target ) return true ; 
       if( idx >= n ) return false ; 
       if( sum > target) return false ; 
       bool take = solve(arr,target,idx+1,sum+arr[idx]) ; 
       bool nottake = solve(arr,target,idx+1,sum) ; 
       
       return t[idx][sum] = (take||nottake) ; 
   }
   
    bool canPartition(vector<int>& arr) {
        memset(t,-1,sizeof(t)) ; 
        int total = accumulate(arr.begin(),arr.end(),0) ; 
        
        if( total % 2 != 0 ) return false ;
        
        return solve(arr,total/2,0,0) ; 
    }
};