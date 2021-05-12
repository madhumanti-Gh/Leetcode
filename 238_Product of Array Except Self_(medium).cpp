// Space Complexity : O(1), Time Complexity : O(n), Without using division operation
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int p = nums[0];
        ans.push_back( 1 );
        for( int i = 1 ; i < n ; i++ ){
            ans.push_back( p );
            p = p * nums[i];
        }
        cout<<endl;
        p = nums[n-1];
        for( int i = n-2 ; i >= 0 ; i-- ){
            ans[i] = p * ans[i];
            p = p* nums[i];
        }
        
        return ans;
    }
};

/*
// Space Complexity : O(n), Time Complexity : O(n), Without using division operation
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int left[n];
        int right[n];
        left[ 0 ] = nums[ 0 ];
        right[ n - 1 ] = nums[ n - 1 ];
        for( int i=1;i<n;i++ ){
            left[i] = nums[i] * left[i-1];
        }
        for( int i=n - 2;i>=0;i-- ){
            right[i] = nums[i] * right[i+1];
        }
        ans.push_back(right[1]);
        for( int i=1;i<n-1;i++ ){
            ans.push_back(left[i-1] * right[i+1]);
        }
        ans.push_back(left[n-2]);
        return ans;
    }
};
*/
