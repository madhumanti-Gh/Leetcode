class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int steps = 0, cur = target;
        while( cur > 1 ){
            if( cur%2 == 0 && maxDoubles > 0 ){
                cur /= 2;
                steps++;
                maxDoubles--;
            }
            else if( cur%2 == 1 ){
                cur--;
                steps++;
            }
            if( maxDoubles == 0 ){
                steps += (cur-1);
                cur = 0;
            }
        }
        return steps;
    }
};
