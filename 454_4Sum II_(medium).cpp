class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;
        for( int& i : nums4 ){
            for( int& j : nums3 ){
                mp[i+j]++;
            }
        }
        int temp, count = 0;
        for( int& i : nums1 ){
            for( int& j : nums2 ){
                temp = i+j;
                count += mp[0-temp];
            }
        }
        return count;
    }
};
