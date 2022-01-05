class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort( asteroids.begin(), asteroids.end() );
        int n = asteroids.size(), i;
        long long M = mass;
        for( i = 0; i < n; i++ ){
            if( M >= asteroids[i] )M += (long long)asteroids[i];
            else return false;
        }
        return true;
    }
};
