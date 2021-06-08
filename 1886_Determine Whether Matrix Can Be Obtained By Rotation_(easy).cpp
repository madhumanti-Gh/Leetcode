class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        for( int p = 0; p < 4; p++ ){
        int left = 0;
        int top = 0;
        int right = n-1;
        int btm = n-1;
        int temp1, temp2;
        while( left < right && top < btm ){
            for( int i = left; i < right; i++ ){
                temp1 = mat[top+i - left][right];
                mat[top+i - left][right] = mat[top][left+i - left];
                temp2 = mat[btm][right - i + left];
                mat[btm][right-i +left] = temp1;
                temp1 = mat[btm-i + left][left];
                mat[btm -i+left][left] = temp2;
                mat[top][left+i-left] = temp1;
            }
            top++;left++;btm--;right--;
        }
            
        if( mat == target )return true;
        }
        return false;
    }
};
