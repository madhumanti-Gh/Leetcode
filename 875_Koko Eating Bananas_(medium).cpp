class Solution {
private:
    long long check( int& k, vector<int>& piles ){
        long long cnt = 0;
        int i, n = piles.size();
        for( i = 0; i < n; i++ ){
            cnt += ( long long )( piles[i]/k );
            if( piles[i]%k != 0 )cnt += 1;
        }
        return cnt;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), i;
        sort( piles.begin(), piles.end() );
        if( h == n )return piles[n-1];
        
        int left, right, mid;
        long long k;
        left = 1;
        right = piles[n-1];
        while( left <= right ){
            mid = left + (right - left)/2;
            k = check( mid, piles );
            if( k <= h ){
                right = mid-1;
            }
            else left = mid +1;
        }
        return left;
    }
};
// Explained here-> (https://leetcode.com/problems/koko-eating-bananas/discuss/1704281/binary-search-approach-explained)
