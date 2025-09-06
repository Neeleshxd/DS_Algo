class Solution {
  public:
    int t[100001][2][3] ; 
    int solve(vector<int> &prices,int idx ,bool buy,int cap ){
        int n = prices.size() ; 
        if( idx == n ) return 0 ;
        if( cap == 0 ) return 0 ; 
        if(t[idx][buy][cap] != -1 ) return t[idx][buy][cap] ; 
        int profit = 0 ; 
        if(buy){
            profit = max(-prices[idx]+solve(prices,idx+1,0,cap),0+solve(prices,idx+1,1,cap)) ; 
        }else{
            profit = max(prices[idx]+solve(prices,idx+1,1,cap-1),0+solve(prices,idx+1,0,cap)) ; 
        }
        return  t[idx][buy][cap] = profit ; 
    }
    int maxProfit(vector<int> &prices) {
        // code here
        memset(t,-1,sizeof(t)) ; 
        return solve(prices,0,1,2) ; 
    }
};