class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, min_len = INT_MAX;
        long long int sum = 0;
        while( r < n ){
            sum += nums[r];
            r++;
            while( sum >= target ){
                min_len = min( min_len, r-l );
                sum -= nums[l];
                l++;
            }
        }
        if( min_len == INT_MAX )return 0;
        return min_len;
    }
};
