class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size(), i, mx = nums[0], beauty = 0;
        
        vector<int> mins( n );
        mins[n-1] = nums[n-1];
        for( i = n-2; i >= 0; i-- ){
            mins[i] = min( nums[i], mins[i+1] );
        }
        
        for( i = 1; i < n; i++ ){
            if( mx <= mins[i] )return i;
            mx = max( mx, nums[i] );
        }
        return 0;
    }
};
