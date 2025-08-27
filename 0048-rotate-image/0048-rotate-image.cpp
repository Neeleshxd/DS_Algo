class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        for( int i = 0; i < n ; i++ ){ // Transpose find karra 
            for( int j = i+1 ; j < m ;j++ ){
                swap(matrix[i][j],matrix[j][i]) ; 
            }
        }
        for( int j = 0 ;j < n ;j++ ){ // We just reverse the rows in this case from i to k  where i is travesing the row till k 
            for( int i = 0 , k = m-1 ; i < k ;i++,k--){
                swap(matrix[j][i],matrix[j][k]) ; 
            }
        }
    }
};