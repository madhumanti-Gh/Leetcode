class Solution {
public:
    bool isPrime( int num ){
        for( int i = 2; i <= sqrt(num); i++ ){
            if( num%i == 0 )return false;
        }
        return true;
    }
    int countPrimes(int n) {
        vector<bool> primes(n+1, 0);
        for( int i = 2; i <= sqrt(n); i++ ){
            if( primes[i] )continue;
            if( isPrime(i) ){
                int base = i;
                while( base*i <= n ){
                    primes[base*i] = true;
                    base++;
                }
            }
        }
        int count = 0;
        for( int i = 2; i < n; i++ ){
            if( !primes[i] )count++;
        }
        return count;
    }
};
