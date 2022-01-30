class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if( k == 0 )return nums;
        int n = nums.size(), start = 0, end = 0, i = k;
        vector<int> ans( n, -1 );
        if( (2 * k + 1 ) > n )return ans;
        
        long long sum = 0;
        while( end < n ){
            sum += nums[end];
            if( end >= 2*k ){
                ans[i] = sum/( end - start + 1 );
                i++;
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans;
    }
};
