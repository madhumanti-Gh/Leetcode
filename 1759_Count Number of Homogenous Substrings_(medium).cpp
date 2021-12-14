class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size(), i, j, count = 0, len = 1;
        long long M = 1000000007, cur;
        if( n == 1 )return 1;
        i = 0;
        j = 1;
        char value = s[0];
        while( i < j && j <= n ){
            if( j == n || s[j] != value ){
                cur = ( ( (len%M) * (len+1) %M) /2 )%M;
                count = ( (count%M) + (cur%M) )%M;
                if( j == n )break;
                i = j;
                len = 1;
                value = s[i];
            }
            else len++;
            j++;
        }
        return count;
    }
};
