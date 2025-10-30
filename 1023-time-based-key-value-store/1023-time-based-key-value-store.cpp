class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>keyscore ; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyscore[key].emplace_back(timestamp,value) ; 
     }
    
    string get(string key, int timestamp) {
        auto&value = keyscore[key] ; 
        int n = value.size() ; 
        int l = 0 ;
        int h = n-1 ; 
        
        string result = "" ; 
        while( l <= h ){
            int mid = l+(h-l) / 2 ; 

            if( value[mid].first <= timestamp){
                result = value[mid].second ; 
                l = mid +1 ; 
            }else{
                h = mid - 1 ;
            }
        }
        return result ; 
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */