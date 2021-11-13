class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size(), m = 0;
        vector<int> ans;
        for( int i = 0; i < n; i++ ){
            if( abs(nums[i]) == n ){
                m++;
            }
            else if( nums[abs(nums[i])] > 0 ){
                nums[abs(nums[i])] = 0- nums[abs(nums[i])];
            }
        }
        for( int i = 1; i < n; i++ ){
            if( nums[i] > 0 ){
                ans.push_back(i);
            }
        }
        if( m == 0 )ans.push_back(n);
        return ans;
    }
};
