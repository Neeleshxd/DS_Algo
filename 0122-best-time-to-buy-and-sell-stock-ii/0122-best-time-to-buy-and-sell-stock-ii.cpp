class Solution {
public:
   int t[30001][2] ; 
    int solve(vector<int>& prices,int idx , bool buy){
       int n = prices.size() ; 
       if(t[idx][buy] != -1 ) return t[idx][buy] ; 
       if( idx == n ) return 0 ; 
       int profit = 0 ; 
       if(buy){
          profit = max(-prices[idx]+solve(prices,idx+1,0),0+solve(prices,idx+1,1)) ; 
       }else{
          profit = max(prices[idx]+solve(prices,idx+1,1),0+solve(prices,idx+1,0)) ; 
       }
       return t[idx][buy] = profit ; 
    }
    int maxProfit(vector<int>& prices) {
        memset(t,-1,sizeof(t)) ; 
        return solve(prices,0,1) ; 
    }
};