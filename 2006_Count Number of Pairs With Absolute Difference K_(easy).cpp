class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size(), i, j, ans = 0;
        for( i = 0; i < n-1; i++ ){
            for( j = i+1; j < n; j++ ){
                if( abs( nums[i] - nums[j] ) == k )ans++;
            }
        }
        return ans;
    }
};
