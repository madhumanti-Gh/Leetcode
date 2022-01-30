class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size(), i, sum = 0, left = 0, right = 0, score = 0, max_score = 0;
        for( int& i : nums )sum += i;
        right = sum;
        max_score = sum;
        vector<int> idx;
        for( i = 1; i <= n; i++ ){
            if( nums[i-1] == 0 )left++;
            else right--;
            score = left + right;
            max_score = max( max_score, score );
        }
        if( max_score == sum )idx.push_back( 0 );
        left = 0;
        right = sum;
        for( i = 1; i <= n; i++ ){
            if( nums[i-1] == 0 )left++;
            else right--;
            score = left + right;
            if( score == max_score )idx.push_back( i );
        }
        return idx;
    }
};
