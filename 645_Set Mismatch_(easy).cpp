class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup, miss;
        for( int i = 0; i < nums.size(); i++ ){
            if( nums[abs(nums[i]) -1] < 0 ){
                dup = abs(nums[i]);
                continue;
            }
            nums[abs(nums[i]) -1] = 0- nums[abs(nums[i]) -1];
        }
        for( int i = 0; i < nums.size(); i++ ){
            if( nums[i] > 0 ){
                miss = i+1;
                break;
            }
        }
        return {dup, miss};
    }
};
