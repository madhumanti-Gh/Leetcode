class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int l = 0, r = m-1, t = 0, b = n-1, dr = 0;
        while( t <= b && l <= r ){
            if( dr == 0){
                for( int i = l; i <= r; i++ ){
                    ans.push_back( matrix[t][i] );
                }
                t++;
            }
            else if( dr == 1){
                for( int i = t; i <= b; i++ ){
                    ans.push_back( matrix[i][r] );
                }
                r--;
            }
            else if( dr == 2 ){
                for( int i = r; i >= l; i-- ){
                    ans.push_back( matrix[b][i] );
                }
                b--;
            }
            else if( dr == 3){
                for( int i = b; i >= t; i-- ){
                    ans.push_back( matrix[i][l] );
                }
                l++;
            }
            dr = ( dr + 1 )%4;
        }
        return ans;
    }
};
