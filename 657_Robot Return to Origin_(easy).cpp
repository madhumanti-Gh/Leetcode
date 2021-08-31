class Solution {
public:
    bool judgeCircle(string moves) {
        int xside = 0;
        int yside = 0;
        for( int i = 0; i < moves.size(); i++ ){
            if( moves[i] == 'L' )xside++;
            else if( moves[i] == 'R' )xside--;
            else if( moves[i] == 'U' )yside++;
            else if( moves[i] == 'D' )yside--;
        }
        if( xside | yside )return false;
        return true;
    }
};
