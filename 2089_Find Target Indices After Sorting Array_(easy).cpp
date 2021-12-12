class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count_target = 0, count_less = 0, n = nums.size(), i;
        for( i = 0; i < n; i++ ){
            if( nums[i] < target ){
                count_less++;
            }
            else if( nums[i] == target ){
                count_target++;
            }
        }
        if( count_target == 0 )return {};
        vector<int> ans;
        i = count_less;
        while( count_target > 0 ){
            ans.push_back(i);
            i++;
            count_target--;
        }
        return ans;
    }
};
