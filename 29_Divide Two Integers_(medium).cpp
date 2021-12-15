class Solution {
public:
    int divide(int dividend, int divisor) {
        if( dividend == 1<<31 && divisor == -1 )return INT_MAX;
        if( dividend == 1<<31 && divisor == 1 )return INT_MIN;
        
        bool sign;
        if( (dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0) )sign = true;
        else sign = false;
        dividend = abs( dividend );
        divisor = abs( divisor );
        
        long long quotient = 0;
        long long count = 0;
        long long divid = (long long)dividend;
        long long divis = (long long)divisor;
        while( divid-divis >= 0 ){
            count = 0;
            while( divid >= (divis << 1 << count) ){
                count++;
            }
            divid -= (divis<<count);
            quotient += (1<<count);
        }
        if( !sign )return 0-quotient;
        return quotient;
    }
};
