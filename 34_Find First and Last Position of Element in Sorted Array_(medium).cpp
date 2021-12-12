class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), i;
        if( n == 0 || nums[0] > target || nums[n-1] < target )return {-1, -1};
        if( nums[0] == target && nums[n-1] == target )return {0, n-1};
        int low = 0, mid;
        int high = n-1;
        while( low <= high ){
            mid = low + (high - low)/2;
            if( nums[mid] < target && nums[mid+1] == target )break;
            else if( nums[mid] >= target )high = mid-1;
            else low = mid+1;
        }
        vector<int> ans(2, -1);
        if( nums[0] == target )ans[0] = 0;
        else if( nums[mid] < target && nums[mid+1] == target )ans[0] = mid+1;
        else return {-1, -1};
        low = ans[0]+1;
        high = n-1;
        while( low <= high ){
            mid = low + (high - low)/2;
            if( nums[mid-1] == target && nums[mid] > target )break;
            else if( nums[mid] > target )high = mid-1;
            else low = mid+1;
        }
        if( nums[n-1] == target )ans[1] = n-1;
        else if( nums[mid-1] == target && nums[mid] > target )ans[1] = mid-1;
        return ans;
    }
};
