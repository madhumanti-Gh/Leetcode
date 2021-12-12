class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), low, high, mid, count, i;
        low = matrix[0][0];
        high = matrix[n-1][n-1];
        while( low <= high ){
            mid = low+ (high - low)/2;
            count = 0;
            for( i = 0; i < n; i++ ){
                count += upper_bound( matrix[i].begin(), matrix[i].end(), mid ) - matrix[i].begin();
            }
            if( count < k )low = mid +1;
            else high = mid -1;
        }
        return low;
    }
};
