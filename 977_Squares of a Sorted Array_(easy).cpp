class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n-1, cur = n-1;
        vector<int> ans(n);
        while( left <= right ){
            if( abs( nums[left] ) >= abs( nums[right] ) ){
                ans[cur] = nums[left]*nums[left];
                left++;
            }
            else{
                ans[cur] = nums[right]*nums[right];
                right--;
            }
            cur--;
        }
        return ans;
    }
};
