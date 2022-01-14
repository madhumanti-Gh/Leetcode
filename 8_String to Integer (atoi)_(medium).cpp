class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0, j = 0, sign = 1;
        long long num = 0;
        while( j < n && s[j] == ' ' ){
            j++;
        }
        if( s[j] == '+' || s[j] == '-' ){
            if( s[j] == '-' )sign = -1;
            j++;
        }
        while( s[j] >= '0' && s[j] <= '9' ){
            num = ( num*10 + ( s[j] - '0' ) );
            if( num > INT_MAX ){
                if( sign == 1 )return INT_MAX;
                else return INT_MIN;
            }
            j++;
        }
        return (sign * num );
    }
};
