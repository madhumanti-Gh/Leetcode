class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n = nums.size(), i, low = nums[0], high = nums[0];
        for( i = 0; i < n; i++ ){
            low = min( low, nums[i] );
            high = max( high, nums[i] );
        }
        low = low +k;
        high = high -k;
        return max( 0, high-low );
    }
};
