class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_spend = accumulate(cost.begin(),cost.end(),0) ; 
        int total_avail = accumulate(gas.begin(),gas.end(),0) ;

        if( total_spend > total_avail) return -1 ;

        int total = 0;
        int result = 0 ; 
        int n = gas.size() ; 
        for( int i = 0 ; i < n ; i++){
           total += gas[i] - cost[i] ; 

           if( total < 0 ){
            result = i+1; 
            total = 0; 
           }
        }
        return result ; 
    }
};