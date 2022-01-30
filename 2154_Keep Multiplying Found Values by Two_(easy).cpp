class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> mp;
        int n = nums.size(), i;
        for( i = 0; i < n; i++ ){
            mp[nums[i]]++;
        }
        while( true ){
            if( mp[original] > 0 )original *= 2;
            else break;
        }
        return original;
    }
};
