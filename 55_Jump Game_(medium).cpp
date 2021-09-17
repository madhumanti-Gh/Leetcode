class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for( int i = 0; i < n; i++ ){
            if( idx < i )return false;
            if( nums[i]+i >= idx )idx = i + nums[i];
            if( idx == n-1 )break;
        }
        if( idx >= n-1 )return true;
        return false;
    }
};
