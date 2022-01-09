class Solution {
public:
    bool isRobotBounded(string instructions) {
        int n = instructions.size(), i, facing = 0, x = 0, y = 0;
        
        for( i = 0; i < n; i++ ){
            if( instructions[i] == 'G' ){
                if( facing == 0 )y++;
                if( facing == 1 )x++;
                if( facing == 2 )y--;
                if( facing == 3 )x--;
            }
            else if( instructions[i] == 'L' ){
                facing -= 1;
                if( facing == -1 )facing = 3;
            }
            else if( instructions[i] == 'R' ){
                facing += 1;
                if( facing == 4 )facing = 0;
            }
        }
        if( ( x == 0 && y == 0 ) || facing != 0 )return true;
        return false;
    }
};
