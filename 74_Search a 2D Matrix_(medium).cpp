class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.size() == 0 && matrix[0].size() == 0 ){
            return false;
        }
        int N = matrix.size();
        int M = matrix[0].size();
        int n = 0, m = M-1, p = N*M;
        while( n < N && m >=0 )
        {
            if( matrix[n][m] == target ){
                return true;
            }
            if( matrix[n][m] > target ){
                m--;
            }
            else{
                n++;
            }
            p--;
            if(p == 0){
                break;
            }
        }
        return false;
    }
};
