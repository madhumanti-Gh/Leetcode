class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size(), high = 0, i, j, left = 0, right, res, max_int = 0;
        int pre[n];
        if( hours[0] > 8 ){
            high++;
            pre[0] = 1;
        }
        else pre[0] = -1;
        for( i = 1; i < n; i++ ){
            if( hours[i] > 8 )pre[i] = pre[i-1] +1;
            else pre[i] = pre[i-1] -1;
        }
        for( i = 0; i < n; i++ ){
            for( j = i; j < n; j++ ){
                if( i > 0 )left = pre[i-1];
                right = pre[j];
                res = right - left;
                if( res > 0 )max_int = max( max_int, j-i+1 );
            }
        }
        return max_int;
    }
};
