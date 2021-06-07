class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        int top = 0;
        int left = 0;
        int right = n-1;
        int btm = n-1;
        int temp1, temp2;
        
        while( left < right && top < btm ){
            
            for( int i = left; i < right; i++ ){
                temp1 = m[top+i - left][right];
                m[top+i - left][right] = m[top][left+i - left];
                temp2 = m[btm][right - i + left];
                m[btm][right-i +left] = temp1;
                temp1 = m[btm-i + left][left];
                m[btm -i+left][left] = temp2;
                m[top][left+i-left] = temp1;
            }
            left++;top++;
            right--;btm--;
        }
    }
};


// Another Solution [ O(n) Timr complexity, O(1) Space Complexity ]
class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        int left;
        int right;
        
        //Find transpose
        for( int i = 0; i < n; i++ ){
            for( int j = i + 1; j < n; j++ ){
                swap( m[i][j], m[j][i] );
            }
        }
        
        // Swap the columns
        for( int i = 0; i < n; i++ ){
            left = 0;
            right = n-1;
            while( left < right ){
                swap( m[i][left++], m[i][right--] );
            }
        }
    }
};
