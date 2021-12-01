class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 1;
        while( even < n && odd < n ){
            if( nums[even]%2 == 1 && nums[odd]%2 == 0 ){
                swap( nums[even], nums[odd] );
            }
            else if( nums[even]%2 == 0 && nums[odd]%2 == 0 ){
                odd-= 2;
            }
            else if( nums[even]%2 == 1 && nums[odd]%2 == 1){
                even -= 2;
            }
            even += 2;
            odd += 2;
        }
        return nums;
    }
};
