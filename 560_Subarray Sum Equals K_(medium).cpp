class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long int sum = 0;
        int n = nums.size();
        int cnt = 0;
        map<long long int, int> freq;
        if( nums[0] == k )cnt++;
        freq[nums[0]]++;
        
        for( int i = 1; i < n; i++ ){
            nums[i] = nums[i] + nums[i-1];
            if( nums[i] == k )cnt++;
            if( freq[nums[i] - k] > 0 )cnt += freq[nums[i] - k];
            freq[nums[i]]++;
        }
        return cnt;
    }
};
