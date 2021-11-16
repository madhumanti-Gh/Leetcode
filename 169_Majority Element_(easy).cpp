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

// using map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for( int i = 0; i < n; i++ ){
            mp[nums[i]]++;
            if( mp[nums[i]] > n/2 ){
                return nums[i];
            }
        }
        return 0;
    }
};
