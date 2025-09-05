class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ; 
        int mini = prices[0] ; 

        int max_profit =  0 ;

        for( int i = 1 ; i< n ; i++ ){
           int cost = prices[i] - mini ; 
           max_profit = max(max_profit ,cost) ; 
           mini = min(mini,prices[i]) ; 
        }
        return max_profit ;  
    }
};