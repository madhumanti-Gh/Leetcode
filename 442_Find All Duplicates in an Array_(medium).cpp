class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int m = nums.size(), n = 0;
        vector<int> ans;
        for( int i = 0; i < m; i++ ){
            if( abs(nums[i]) == m ){
                n++;
                continue;
            }
            if( nums[abs(nums[i])] < 0 ){
                ans.push_back(abs(nums[i]));
            }
            else{
                nums[abs(nums[i])] = 0- nums[abs(nums[i])];
            }
        }
        if( n == 2 ){
            ans.push_back(m);
        }
        return ans;
    }
};
