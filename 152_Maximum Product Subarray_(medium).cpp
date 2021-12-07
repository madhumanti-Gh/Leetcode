class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0, tneg = 0, neg_id = -1, neg_val = 1, prod = 1, max_pro = INT_MIN;
        while( i <= j && j < n ){
            if( nums[j] == 0 ){
                i = j+1;
                j = j+1;
                tneg = 0;
                neg_id = -1;
                neg_val = 1;
                prod = 1;
                max_pro = max( max_pro, 0 );
                continue;
            }
            if( nums[j] < 0 ){
                tneg++;
                if( tneg == 1 ){
                    neg_id = j;
                    neg_val = nums[j]*prod;
                }
            }
            prod *= nums[j];
            if( tneg%2 == 0 ){
                max_pro = max( max_pro, prod );
            }
            else{
                if( j != neg_id )max_pro = max( max_pro, prod/neg_val );
                else max_pro = max( max_pro, nums[j] );
            }
            j++;
        }
        return max_pro;
    }
};
