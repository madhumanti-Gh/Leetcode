class Solution {
private:
    int find_pile( vector<int>& piles, int l, int r, vector<vector<int>>& dp ){
        if( dp[l][r] != -1 )return dp[l][r];
        if( l > r )return 0;
        if( l == r )return piles[l];
        if( l+1 == r ){
            return max( piles[l], piles[r] );
        }
        int A, B;
        A = piles[l] + min( find_pile( piles, l+2, r, dp ), find_pile( piles, l+1, r-1, dp ) );
        B = piles[r] + min( find_pile( piles, l, r-2, dp ), find_pile( piles, l+1, r-1, dp ) );
        return dp[l][r] =  max( A, B );
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size(), i, sum = 0;
        for( auto& s : piles )sum += s;
        vector<vector<int>> dp( n+1, vector<int> ( n+1, -1 ) );
        if( find_pile( piles, 0, n-1, dp ) > sum/2 )return true;
        return false;
    }
};
