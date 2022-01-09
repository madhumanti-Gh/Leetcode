class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size(), i, j, p, q;
        vector<int> answer( m, 0 );
        for( p = 0; p < m; p++ ){
            i = startPos[0];
            j = startPos[1];
            for( q = p; q < m; q++ ){
                answer[p]++;
                if( s[q] == 'L' )j--;
                if( s[q] == 'R' )j++;
                if( s[q] == 'U' )i--;
                if( s[q] == 'D' )i++;
                if( i < 0 || i >= n || j < 0 || j >= n ){
                    answer[p]--;
                    break;
                }
            }
        }
        return answer;
    }
};
