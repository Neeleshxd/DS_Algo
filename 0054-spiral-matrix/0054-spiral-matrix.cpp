class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &mat) {
        // code here
        int n = mat.size() ;
        int m = mat[0].size() ; 
        
        int left = 0; 
        int right = m-1 ; 
        int top = 0;
        int bottom = n-1; 
        vector<int>result ; 
        while( left <= right && top <= bottom ){
            
            for( int i = left ; i <= right ; i++ ){
                result.push_back(mat[top][i]) ; 
            }
            top++; 
            for( int i = top ; i <= bottom ; i++ ){
                result.push_back(mat[i][right]) ; 
            }
            right--; 
            if( top <= bottom ){
              for( int i = right ; i >= left ; i-- ){
                result.push_back(mat[bottom][i]) ; 
            }
            bottom--; 
            }
            if( left <= right ){
                for( int i = bottom ; i >= top ; i-- ){
                result.push_back(mat[i][left]) ; 
            }
            left++;
            }
        }
        return result ; 
    }
};