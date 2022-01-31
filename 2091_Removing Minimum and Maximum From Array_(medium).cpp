class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), mxi = 0, mni = 0, i, d1, d2, dist = INT_MAX;
        for( i = 0; i < n; i++ ){
            if( nums[i] < nums[mni] )mni = i;
            if( nums[i] > nums[mxi] )mxi = i;
        }
        // Distance from left end
        d1 = mni +1;
        d2 = mxi +1;
        dist = min( dist, max( d1, d2 ) );
        // Distance from right end
        d1 = n - mni;
        d2 = n - mxi;
        dist = min( dist, max( d1, d2 ) );
        // Distance from both end
        if( mni < mxi ){
            d1 = mni +1;
            d2 = n - mxi;
        }
        else{
            d1 = n - mni;
            d2 = mxi +1;
        }
        dist = min( dist, d1 + d2 );
        return dist;
    }
};
