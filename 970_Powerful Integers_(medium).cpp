class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if( x == 1 && y == 1 ){
            if( bound >= 2 )return {2};
            return {};
        }
        vector<int> px, py;
        int powx = x, powy = y;
        px.push_back( 1 );
        py.push_back( 1 );
        while( x != 1 && powx < bound ){
            px.push_back( powx );
            powx *= x;
        }
        while( y != 1 && powy < bound ){
            py.push_back( powy );
            powy *= y;
        }
        set<int> st;
        int n = px.size(), m = py.size(), i, j;
        for( i = 0; i < n; i++ ){
            for( j = 0; j < m; j++ ){
                if( px[i] + py[j] <= bound )st.insert( px[i] + py[j] );
                else break;
            }
        }
        px.clear();
        while( !st.empty() ){
            px.push_back( *st.begin() );
            st.erase( st.begin() );
        }
        return px;
    }
};
