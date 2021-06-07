class Solution {
public:
    
    void reversing( vector<int>& nums, int low, int high ){
        int temp;
        while( low < high ){
            temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if( k >= n ){
            k = k%n;
        }
        if( k > 0 ){
        reversing( nums, 0, n-1 );
        reversing( nums, 0, k - 1 );
        reversing( nums, k, n - 1 );
        }
    }
};
