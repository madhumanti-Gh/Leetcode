class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), i, j, dif;
        int max_len = 1;
        vector<vector<int>> dp( n+1, vector<int> ( 1002, 1 ) );
        for( i = 0; i < n; i++ ){
            for( j = i+1; j < n; j++ ){
                dif = nums[j] - nums[i] + 500;
                dp[j][dif] = dp[i][dif] +1;
                max_len = max( max_len, dp[j][dif] );
            }
        }
        return max_len;
    }
};
