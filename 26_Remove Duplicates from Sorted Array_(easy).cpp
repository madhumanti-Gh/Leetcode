class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if( nums.size() == 0 )return 0;
        int p=nums[0], n = 1;
        vector<int>:: iterator it1;
        it1 = nums.begin();it1++;
        while( it1 != nums.end() ){
            if( *it1 == p ){
                nums.erase( it1 );
                it1--;
            }
            else{
                p = *it1;
            }
            it1++;
        }
        return nums.size();
    }
};

// Faster
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if( nums.size() == 0 )return 0;
        int i = 1, j = 0, n = nums.size();
        while( i < n ){
            if( nums[j] != nums[i] ){
                j++;
                nums[j] = nums[i];
            }
            ++i;
        }
        return j+1;
    }
};
