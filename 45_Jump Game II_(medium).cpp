class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), i, cur, last, step;
        if( n == 1 )return 0;
        cur = nums[0];
        last = cur;
        step = 1;
        for( i = 1; i < n; i++ ){
            if( cur >= n-1 )break;
            if( i+ nums[i] > last )
                last = i+ nums[i];
            if( i == cur ){
                step++;
                cur = last;
            }
        }
        return step;
    }
};
