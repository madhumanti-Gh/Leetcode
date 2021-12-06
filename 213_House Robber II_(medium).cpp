class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), i;
        if( n == 1 )return nums[0];
        if( n == 2 )return max( nums[0], nums[1] );
        if( n == 3 )return max( nums[0], max( nums[1], nums[2] ) );
        vector<int> dp1(n-1, 0), dp2(n, 0);
        dp1[0] = dp1[1] = nums[0];
        dp2[1] = nums[1];
        dp2[2] = max( nums[1], nums[2] );
        for( i = 2; i < n-1; i++ ){
            dp1[i] = max( nums[i]+ dp1[i-2], dp1[i-1] );
        }
        for( i = 3; i < n; i++ ){
            dp2[i] = max( nums[i]+ dp2[i-2], dp2[i-1] );
        }
        return max( dp1[n-2], dp2[n-1] );
    }
};
