class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int el2 = nums[0],el1 = nums[0];
        int fr2 = 1, fr1 = 1;
        for( int i=1; i<nums.size(); i++ ){
            if( nums[i] == el1 ){
                fr1++;
            }
            else{
                if( fr2 < fr1 ){
                    fr2 = fr1;
                    el2 = el1;
                }
                el1 = nums[i];
                fr1 = 1;
            }
        }
        if( fr2 < fr1 ){
            fr2 = fr1;
            el2 = el1;
        }
        return el2;
    }
};
