class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        int n = nums.size(), i;
        vector<int> ans;
        if( n == 1 || ( nums[1] > nums[0]+1 ) )ans.push_back( nums[0] );
        for( i = 1; i < n-1; i++ ){
            if( nums[i-1] +1 < nums[i] && nums[i+1] -1 > nums[i] )ans.push_back( nums[i] );
        }
        if( n > 1 && nums[n-1] > nums[n-2]+1 )ans.push_back( nums[n-1] );
        return ans;
    }
};
