class Solution {
public:
    int countPoints(string rings) {
        vector<string> rod(10, "rgb" );
        int n = rings.size(), i, count = 0;
        for( i = 0; i < n; i += 2 ){
            char c = rings[i];
            int id = rings[i+1] -48;
            if( c == 'B' )rod[id][2] = 'B';
            if( c == 'G' )rod[id][1] = 'G';
            if( c == 'R' )rod[id][0] = 'R';
        }
        for( i = 0; i < 10; i++ ){
            if( rod[i][0] == 'R' && rod[i][1] == 'G' && rod[i][2] == 'B' )count++;
        }
        return count;
    }
};
