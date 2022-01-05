class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int beams = 0, n = bank.size(), m, i, prev = 0, cur = 0;
        for( auto str : bank ){
            m = str.size();
            cur = 0;
            for( i = 0; i < m; i++ ){
                if( str[i] == '1' )cur++;
            }
            if( cur > 0 ){
                beams += (prev * cur);
                prev = cur;
            }
        }
        return beams;
    }
};
