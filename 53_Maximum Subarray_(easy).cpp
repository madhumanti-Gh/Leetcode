class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        int max_sum = sum;
        for( int i = 1; i < n; i++ ){
            sum += nums[i];
            if( sum < nums[i] )sum = nums[i];
            if( max_sum < sum )max_sum = sum;
        }
        
        return max_sum;
    }
};
