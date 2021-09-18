class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 )return nums[0];
        if( n == 2 && nums[0] != nums[1] )return nums[0];
        map<int, int> mp;
        for( int i = 0; i < n; i++ )mp[nums[i]]++;
        for( int i = 0; i < n; i++ ){
            if( mp[nums[i]] == 1 )return nums[i];
        }
        return 0;
    }
};

// Another method
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 )return nums[0];
        sort( nums.begin(), nums.end() );
        if( nums[0] != nums[1] )return nums[0];
        if( nums[n-1] != nums[n-2] )return nums[n-1];
        for( int i = 1; i < n; i++ ){
            if( nums[i] != nums[i-1] )return nums[i-1];
            i += 2;
        }
        return nums[1];
    }
};
