class Solution {
private:
    int stores( vector<int>& quantities, int num ){
        int cnt = 0, i, n = quantities.size();
        for( i = 0; i < n; i++ ){
            cnt += ( quantities[i]/ num );
            if( quantities[i]%num != 0 )cnt += 1;
        }
        return cnt;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int len = quantities.size(), i;
        sort( quantities.begin(), quantities.end() );
        if( len == n )return quantities[len-1];
        
        int left = 1, right = quantities[len-1], mid, x;
        while( left < right ){
            mid = left + (right - left)/2;
            x = stores( quantities, mid );
            if( x <= n ){
                right = mid;
            }
            else left = mid + 1;
        }
        return left;
    }
};
