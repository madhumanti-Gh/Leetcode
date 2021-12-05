class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size(), i, lowest = nums[0];
        for( i = 1; i < n; i++ ){
            nums[i] = nums[i] + nums[i-1];
            lowest = min( lowest, nums[i] );
        }
        if( lowest > 0 )return 1;
        return 1+ abs(lowest);
    }
};
