class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        int count = 0;
        int n = nums.size();
        for( int i = 0; i < n-2; i++ ){
            int j = i + 1;
            int k = j + 1;
            for( ; j < n-1; j++ ){
                while( k < n && nums[i] + nums[j] > nums[k] ){
                    k++;
                }
                if( k > j ){
                    count += (k - j - 1);
                }
            }
        }
        return count;
    }
};
