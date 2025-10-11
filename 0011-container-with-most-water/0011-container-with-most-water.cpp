class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ; 
        int i = 0 ;
        int j = n-1 ;
        int width =  0 ;
        int max_area = 0 ; 
        while( i < j ){
            width = j-i ; 
            int min_height = min(height[i],height[j]) ; 
            int area = min_height*width ; 
            max_area = max(max_area,area) ; 

            if( height[i] < height[j]){
                i++;
            }else{
                j--; 
            }
        }
        return max_area ; 
    }
};