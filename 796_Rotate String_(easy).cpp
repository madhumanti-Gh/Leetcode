class Solution {
public:
    bool rotateString(string s, string goal) {
        if( s.size() != goal.size() )return false;
        if( s == goal )return true;
        int n = s.size();
        string str = s + s;
        for( int i = 0; i < n; i++ ){
            if( str.substr( i, n ) == goal ){
                return true;
            }
        }
        return false;
    }
};
