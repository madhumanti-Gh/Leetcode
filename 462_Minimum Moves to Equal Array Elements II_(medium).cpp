// Using median
class Solution {
public:
    int cost( vector<int>& nums, int med ){
        long long int sum = 0;
        for( int i = 0; i < nums.size(); i++ ){
            sum += abs(nums[i] - med);
        }
        return sum;
    }
    int minMoves2(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        int n = nums.size();
        int med = nums[n/2];
        
        return cost( nums, med );
    }
};

// Another method (using difference )
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        int n = nums.size(), sum = 0;
        for( int i = 0; i < n/2; i++ ){
            sum += ( nums[n-1-i] - nums[i] );
        }
        return sum;
    }
};

