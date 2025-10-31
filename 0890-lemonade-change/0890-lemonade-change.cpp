class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       unordered_map<int,int>mp ;

       int n = bills.size() ; 
       for( int i = 0 ; i < n ; i++ ){

        if( bills[i] == 10 || bills[i] == 20 ){
            if( bills[i] == 10 ){
                if( mp[5] == 0 ) return false ; 
                mp[5]--; 
            }
            if( bills[i] == 20 ){
                if( mp[10] > 0 && mp[5] > 0 || mp[5] >= 3 ){
                if( mp[10] > 0 && mp[5] > 0){
                mp[10]--;
                mp[5]--; 
                }else{
                    mp[5] -= 3; 
                }
                }else{
                    return false ; 
                } 
            }
        }
        mp[bills[i]]++; 
       }
       return true ;  
    }
};