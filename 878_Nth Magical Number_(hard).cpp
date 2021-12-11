class Solution {
private:
    long long gcd( long long a, long long b ){
        if( b == 0 )return a;
        return gcd( b, a%b );
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long A = min( a, b );
        long long B = max( a, b );
        long long M = 1000000007;
        long long LCM = (A*B)/gcd( B, A );
        long long C = (n*A);
        if( B%A == 0 )return C%M;
        long long low = A, high = C, mid, D;
        while( low < high ){
            mid = (high - low)/2 + low;
            D = ((mid/A) + (mid/B) - (mid/LCM) );
            if( D < n )low = mid+1;
            else high = mid;
        }
        return low%M;
    }
};
