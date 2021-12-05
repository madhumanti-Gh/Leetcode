class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int i, n = nums.size(), mini, maxi, dif, high, low;
        if( n == 1 )return 0;
        sort( nums.begin(), nums.end() );
        high = nums[n-1] -k;
        low = nums[0] +k;
        dif = nums[n-1] - nums[0];
        for( i = 0; i < n-1; i++ ){
            mini = min( nums[i+1] -k, low );
            maxi = max( nums[i] +k, high );
            dif = min( dif, maxi-mini );
        }
        return dif;
    }
};
