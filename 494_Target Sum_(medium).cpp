// Recursion
class Solution {
public:
    int get_target( vector<int>& nums, int target, int n ){
        if( n == 0 ){
            if( target == 0 ){
                return 1;
            }
            return 0;
        }
        int ans;
        ans = get_target( nums, target - nums[n-1], n-1 ) + get_target( nums, target + nums[n-1], n-1 );
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = get_target( nums, target, n );
        return ans;
    }
};

// Recursion + Memoization
class Solution {
public:
    int get_target( vector<int>& nums, int target, int n, map<pair<int, int>, int>& mp ){
        if( n == 0 ){
            if( target == 0 ){
                return 1;
            }
            return 0;
        }
        if( mp.find({n, target}) != mp.end() ){
            return mp[{n, target}];
        }
        int ans;
        ans = get_target( nums, target - nums[n-1], n-1, mp ) + get_target( nums, target + nums[n-1], n-1, mp );
        return mp[{n, target}] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int, int>, int> mp;
        int ans = get_target( nums, target, n, mp );
        return ans;
    }
};
