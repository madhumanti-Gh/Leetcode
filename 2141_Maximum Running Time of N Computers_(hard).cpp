class Solution {
private:
    bool max_time( vector<int>& batteries, int n, long long time ){
        long long total_C = time*n;
        for( auto& battery : batteries ){
            total_C -= min( (long long)battery, time );
        }
        if( total_C <= 0 )return true;
        return false;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for( auto& battery : batteries )sum += (long long)battery;
        long long left = 0, right = sum/n, ans = 0, mid;
        while( left <= right ){
            mid = left + (right - left)/2;
            if( max_time( batteries, n, mid ) ){
                ans = mid;
                left = mid+1;
            }
            else right = mid -1;
        }
        return ans;
    }
};
