class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int len = nums.size(), i, j, n = len/3;
        long long min_dif = 1e13, presum;
        vector<long long> right( len, 0 ), left( len, 0 );
        priority_queue<int, vector<int>, greater<int>> mnh;
        priority_queue<int> mxh;
        
        presum = 0;
        for( i = len-1; i >= n; i-- ){
            presum += nums[i];
            mnh.push( nums[i] );
            if( i > len-n || i < n )continue;
            if( mnh.size() > n ){
                presum -= mnh.top();
                mnh.pop();
            }
            right[i] = presum;
        }
        presum = 0;
        for( i = 0; i < len-n; i++ ){
            presum += nums[i];
            mxh.push( nums[i] );
            if( i < n-1 )continue;
            if( mxh.size() > n ){
                presum -= mxh.top();
                mxh.pop();
            }
            left[i] = presum;
            min_dif = min( min_dif, left[i] - right[i+1] );
        }
        return min_dif;
    }
};
