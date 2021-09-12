class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cnt;
        cnt.push_back(0);
        int c,n = 1,m;
        while( n <= num ){
            c = 0;
            m = n;
            while( m > 0 ){
                c += m&1;
                m >>= 1;
            }
            cnt.push_back(c);
            n++;
        }
        
        return cnt;
    }
};
