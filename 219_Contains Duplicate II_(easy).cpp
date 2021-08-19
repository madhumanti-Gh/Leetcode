class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        if( n == 1 )return false;
        for( int i = 0; i < n; i++ ){
            if( mp[nums[i]] > 0 && abs( i - mp[nums[i]] +1 ) <= k ){
                return true;
            }
            else{
                mp[nums[i]] = i +1;
            }
        }
        return false;
    }
};
