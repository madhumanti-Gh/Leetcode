class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if( n == 1 ){
            if( nums[0] == 1 )return 1;
            else return 0;
        }
        int l = 0, r = 1;
        int max_len = 0;
        while( l < r && r <= n ){
            if( r == n && nums[l] == 1 ){
                max_len = max( max_len, r-l );
                break;
            }
            if( nums[l] != 1 ){
                l++;r++;
            }
            else if( nums[l] == 1 && nums[r] == 0 ){
                max_len = max( max_len, r-l );
                l = r;r++;
            }
            else if( nums[l] == 1 && nums[r] == 1 ){
                r++;
            }
        }
        return max_len;
    }
};
