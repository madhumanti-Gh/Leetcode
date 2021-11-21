class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        int i = 0, j = n;
        vector<int> perm;
        if( s[0] == 'I' ){
            perm.push_back( i );
            i++;
        }
        else if( s[0] == 'D' ){
            perm.push_back( j );
            j--;
        }
        for( int k = 1; k <= n; k++ ){
            if( s[k] == 'I' ){
                perm.push_back( i );
                i++;
            }
            else{
                perm.push_back( j );
                j--;
            }
        }
        return perm;
    }
};
