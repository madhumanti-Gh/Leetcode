class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if( n == 0 )return 0;
        int l = 0, r = n-1;
        while( l < r ){
            if( nums[l] == val && nums[r] != val ){
                swap( nums[l], nums[r] );
                l++;r--;
            }
            else if( nums[r] == val )r--;
            else if( nums[l] != val )l++;
        }
        if( nums[0] == val )return 0;
        if( nums[r] == val )return r;
        return r+1;
    }
};
