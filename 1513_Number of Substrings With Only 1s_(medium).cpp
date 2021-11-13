class Solution {
public:
    int numSub(string s) {
        int n = s.size(), l = 0, r = 0;
        long long int m = 0, c = 0, d = 0, M = 1000000007;
        while( l <= r && r < n ){
            if( s[l] == '0' ){
                l++;r++;
            }
            else if( s[l] == '1' && s[r] == '1' ){
                r++;
            }
            else if( s[l] == '1' && s[r] == '0' ){
                m = r-l;
                if( m%2 == 0 ){
                    d = ((m/2)%M*(m+1)%M )%M;
                    c = (c%M + d%M)%M;
                }
                else{
                    d = (((m%M +1)/2)%M *m%M )%M;
                    c = (c%M + d%M)%M;
                }
                l = r;
            }
        }
        if( s[l] == '1' && r == n && s[r-1] == '1' ){
            m = r-l;
            if( m%2 == 0 ){
                d = ((m/2)%M*(m+1)%M )%M;
                c = (c%M + d%M)%M;
            }
            else{
                d = (((m%M +1)/2)%M *m%M )%M;
                c = (c%M + d%M)%M;
            }
            l = r;
        }
        return c%M;
    }
};
