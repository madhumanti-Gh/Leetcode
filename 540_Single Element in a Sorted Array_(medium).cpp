class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 || nums[0] != nums[1] )return nums[0];
        if( nums[n-2] != nums[n-1] )return nums[n-1];
        int mid,l = 2, r = n-3;
        while( l <= r ){
            mid = l + (r-l)/2 ;
            if( nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1] ){
                return nums[mid];
            }
            if( mid%2 == 0 ){
                if( nums[mid] == nums[mid+1] )l = mid+2;
                else r = mid;
            }
            else{
                if( nums[mid] == nums[mid-1] )l = mid+1;
                else r = mid-1;
            }
        }
        
        return 0;
    }
};
