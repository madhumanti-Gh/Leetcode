class Solution {
public:
    int countElements(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        int n = nums.size(), i = 0, first = nums[0], end = nums[n-1];
        if( first == end )return 0;
        while( i < n && nums[i] == first )i++;
        int j = n-1;
        while( j >= 0 && nums[j] == end )j--;
        return j-i+1;
    }
};
