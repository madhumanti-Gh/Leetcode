class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if( n < 2 )return false;
        map<long long int, int > mp;
        nums[0] = nums[0]%k;
        mp[nums[0]]++;
        for( int i = 1; i < n; i++ ){
            nums[i] = (nums[i] + nums[i-1])%k;
            if( nums[i] == 0 )return true;
            if( ( mp[nums[i]] > 0 && nums[i-1] != nums[i] ) || mp[nums[i]] > 1 )return true;
            mp[nums[i]%k]++;
        }
        return false;
    }
};
