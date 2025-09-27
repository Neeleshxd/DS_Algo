class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int p = points.size() ; 
        double max_area = 0.0 ; 

        for( int i = 0 ; i < p ; i++ ){
            for( int j = i+1 ; j < p ;j++ ){
                for( int k = j+1 ; k < p ; k++ ){
                    int x1 = points[i][0] ;
                    int y1 = points[i][1] ; 

                    int x2 = points[j][0] ;
                    int y2 = points[j][1] ; 

                    int x3 = points[k][0] ;
                    int y3 = points[k][1] ; 

                    double shoelace = 0.5*abs(x1*(y2-y3)+ x2*(y3-y1)+x3*(y1-y2)) ; 
                    max_area = max(max_area,shoelace) ; 
                }
            }
        }
        return max_area ; 
    }
};