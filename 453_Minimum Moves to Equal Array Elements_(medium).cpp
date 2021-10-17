class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = INT_MAX;
        int n = nums.size();
        long long int sum = 0;
        for( int i = 0; i < n; i++ ){
            sum += nums[i];
            min_val = min( nums[i], min_val );
        }
        return (sum - (n*min_val) );
    }
};
