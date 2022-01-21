class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int n = nums.size(), i, mn = INT_MAX, mx, dif, deviation;
        for( i = 0; i < n; i++ ){
            if( nums[i]%2 != 0 )nums[i] *= 2;
            mn = min( mn, nums[i] );
            pq.push( nums[i] );
        }
        deviation = pq.top() - mn;
        while( pq.top()%2 == 0 ){
            mx = pq.top();
            pq.pop();
            mn = min( mn, mx/2 );
            pq.push( mx/2 );
            deviation = min( deviation, pq.top() - mn );
        }
        return deviation;
    }
};
