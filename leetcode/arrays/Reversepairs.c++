// Brute force solution 
#include <bits/stdc++.h>
#include <vector>
class Solution {
public:
    int reversePairs(std::vector<int>& nums) {
        int n = nums.size() ;
        
        long long  pairs = 0 ; 

        for( int i = 0 ; i < n-1 ; i++ ){
        for( int j = i + 1 ; j < n ; j++ ){
        if( i < j ){
        
        if( nums[i] > (long long )nums[j]*2 ){
        pairs++; 
        }
        }
        }
        }
        return pairs ; 
    }
};



// Time complexity : O(n^2)