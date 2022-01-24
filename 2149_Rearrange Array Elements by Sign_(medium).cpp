class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        vector<int> pos, neg;
        i = 0;
        while( i < n ){
            if( nums[i] < 0 )neg.push_back( nums[i] );
            else pos.push_back( nums[i] );
            i++;
        }
        j = 0;
        for( i = 0; i < n; i+= 2 ){
            nums[i] = pos[j];
            nums[i+1] = neg[j];
            j++;
        }
        return nums;
    }
};
