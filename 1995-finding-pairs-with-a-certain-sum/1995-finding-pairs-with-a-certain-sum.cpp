class FindSumPairs {
public:
   vector<int>num1 ;
   vector<int>num2 ; 
   unordered_map<int,int>mp ;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
           num1 = nums1 ;
           num2 = nums2 ; 
            for( int&x : num2 ){
            mp[x]++; 
        }
    }
    
    void add(int index, int val) {
        mp[num2[index]]--; 
        num2[index] = num2[index] + val ; 
        mp[num2[index]]++; 
    }
    
    int count(int tot) {
        int n = num1.size() ;
        int count = 0 ;  
        for( int i = 0 ; i < n ; i++ ){
            if(mp.find(tot - num1[i]) != mp.end() ){
                count += mp[tot - num1[i]] ; 
            }
        }
        return count ; 
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */