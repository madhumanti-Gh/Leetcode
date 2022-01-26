class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), sum = 0, i;
        for( i = 0; i < n; i++ )sum += cardPoints[i];
        if( n == k )return sum;
        
        int ans = 0, window = 0;
        for( i = 0; i < n; i++ ){
            window += cardPoints[i];
            if( i < n-k-1 )continue;
            ans = max( ans, sum - window );
            window -= cardPoints[i - (n-k-1)];
        }
        return ans;
    }
};
