class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size(), count = 0, ele = nums[0];
        while( i <= j && j < n ){
            if( count < 2 ){
                nums[i] = nums[j];
                if( ele == nums[i] ){
                    count++;
                }
                else{
                    ele = nums[i];
                    count = 1;
                }
                i++;j++;
            }
            else{
                count = 0;
                while( j < n && ele == nums[j] ){
                    j++;
                }
            }
        }
        return i;
    }
};
