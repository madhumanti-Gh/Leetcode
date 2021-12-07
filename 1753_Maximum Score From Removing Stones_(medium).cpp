class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a+b+c;
        int A = max( a, max( b, c ) );
        int C = min( a, min( b, c ) );
        int B = sum -A -C;
        int score = 0;
        if( B+C <= A )return (B+C);
        while( sum > max( A, max(B,C) ) ){
            A--;B--;score++;
            sum -= 2;
            B = sum - max( A, max(B,C) ) - min( A, min(B,C) );
            A = max( A, max(B,C) );
            C = sum -A -B;
        }
        return score;
    }
};
