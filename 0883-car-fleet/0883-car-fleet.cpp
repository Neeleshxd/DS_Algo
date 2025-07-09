class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>p ; 
        int n = position.size() ; 
        for( int i = 0 ; i < n ; i++ ){
            p.push_back({position[i],speed[i]}) ; 
        }
        sort(p.rbegin() , p.rend()) ; 
        vector<double>st ; 
        for(auto&it : p ){
            double time = (double) (target - it.first) / it.second ; 
            st.push_back(time) ; 
            if( st.size() >= 2 && st.back() <= st[st.size() - 2 ]){
                st.pop_back() ; 
            }
        }
        return st.size() ; 
    }
};