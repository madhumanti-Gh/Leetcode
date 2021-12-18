class Solution {
public:
    bool check( vector<int>& nums, int k, int mid ){
        int n = nums.size(), i, j, count = 0;
        j = 1;
        for( i = 0; i < n; i++ ){
            while( j < n && nums[j] - nums[i] <= mid )j++;
            count += (j -1 -i );
            if( count >= k )return true;
        }
        if( count >= k )return true;
        return false;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort( nums.begin(), nums.end() );
        int n = nums.size();
        int left = 0, mid;
        int right = nums[n-1] - nums[0];
        while( left < right ){
            mid = left+ ( right - left )/2;
            if( check( nums, k, mid ) )right = mid;
            else left = mid+1;
        }
        return left;
    }
};
