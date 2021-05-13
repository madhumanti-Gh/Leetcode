class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int x = 0;
        for( int i = 0; i < nums.size(); i++ ){
            x = x ^ nums[i];
        }
        // mask value is a number which have only one bit set, that is the same bit as right most set bit of x
        int mask = ( x & (-x) );
        int a = 0, b = 0;
        for( int i = 0; i < nums.size(); i++ ){
            if( mask&nums[i] ){
                a = a^nums[i];
            }
            else{
                b = b^nums[i];
            }
        }
        return {a,b};
    }
};
