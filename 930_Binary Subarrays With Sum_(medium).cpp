class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        int sum = 0;
        map<int, int> mp;
        for( int i = 0; i < n; i++ ){
            sum += nums[i];
            if( sum == goal )count++;
            if( mp[sum - goal] > 0 ){
                count += mp[sum - goal];
            }
            mp[sum]++;
        }
        return count;
    }
};
