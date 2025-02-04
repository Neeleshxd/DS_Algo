//Better Solution 
class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
        int n = nums.size() ;
        if( n == 1 || n == 0 ) return n ; 
        set<int>st ;
        st.insert(nums.begin(),nums.end()) ;

        int j = 1 ;
        int i = 0;
        int sub = 1 ; 
        int max_length = 1 ; 
        nums.assign(st.begin(), st.end());
        while( j < nums.size() ){
        if( nums[j] - nums[j-1] > 1 ){
            sub = j -i ;
            i= j ; 
        }
        max_length = max(j-i+1,max_length) ;
        j++; 
        }
       return max( max_length,sub); 
    }
};// TC O(nlogn) SC O(n)

// Optimized Solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ;
        if(n == 0 ) return 0 ; 
        int max_seq = 1 ;
        unordered_set<int>st;
        st.insert(nums.begin(),nums.end()) ; 
       
        for(auto&it: st ){
         if( st.find(it-1) == st.end()){
               int x = it ;
               int count = 1 ;
        while(st.find(x+1) != st.end()){
                 x = x + 1;
                count = count +1 ;
               }
            max_seq = max(max_seq,count ); 
            }
        }
        return max_seq;  
    }
};// TC O(n) SC O(n)