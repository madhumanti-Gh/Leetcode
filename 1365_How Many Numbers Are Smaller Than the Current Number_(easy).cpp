class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size(), sum = 0, i;
        vector<int> freq(102), ans(n);
        for( i = 0; i < n; i++ ){
            freq[nums[i]]++;
        }
        for( i = 1; i < 102; i++ ){
            freq[i] = freq[i] + freq[i-1];
        }
        for( i = 0; i < n; i++ ){
            if( nums[i] == 0 )continue;
            ans[i] = freq[nums[i] -1];
        }
        return ans;
    }
};
