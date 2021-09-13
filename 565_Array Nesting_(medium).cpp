class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;
        for( int i = 0; i < n; i++ ){
            int k = i, prev = -1, m = 0;
            while( nums[k] != -1 ){
                m++;
                prev = nums[k];
                nums[k] = -1;
                k = prev;
            }
            max_len = max( max_len, m );
        }
        return max_len;
    }
};
