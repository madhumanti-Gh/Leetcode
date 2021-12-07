class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0, neg_idx = -1, tneg = 0, max_len = 0;
        while( i <= j && j < n ){
            if( nums[j] == 0 ){
                i = j+1;
                j = j+1;
                neg_idx = 0;
                tneg = 0;
                continue;
            }
            if( nums[j] < 0 ){
                tneg++;
                if( tneg == 1 )neg_idx = j;
            }
            if( tneg%2 == 0 ){
                max_len = max( max_len, j-i+1 );
            }
            else{
                max_len = max( max_len, j-neg_idx );
            }
            j++;
        }
        return max_len;
    }
};
