class Solution {
public:
    vector<vector< int>> fourSum(vector< int>& nums, int target) {
        int n = nums.size();
        if( n < 4 )return {};
        sort( nums.begin(), nums.end() );
        vector< vector< int> > ans;
        long long int sum;
        int l,r,i,j;
        for( i = 0; i < n; i++ ){
            if( i != 0 && nums[i] == nums[i-1] )continue;
            for( j = i+1; j < n; j++ ){
                if( j != i+1 && nums[j] == nums[j-1] )continue;
                l = j+1;
                r = n -1;
                while( l < r ){
                    sum = (long long int)nums[i] + (long long int)nums[j] + (long long int)nums[l] + (long long int)nums[r];
                    if( sum == target ){
                        ans.push_back( { nums[i], nums[j], nums[l], nums[r] } );
                        while( l < r && nums[l] == nums[l+1] )l++;
                        while( l < r && nums[r] == nums[r-1] )r--;
                        l++;r--;
                    }
                    else if( sum < target )l++;
                    else if( sum > target )r--;
                }
            }
        }
        return ans;
    }
};
