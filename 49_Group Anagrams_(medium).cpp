class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	
        vector< vector < string > > ans;
        vector< string > stra;
        vector< int > strb;
        map< string, vector< int > > fr;
        for( int i = 0 ; i < strs.size() ; i++ ){
            string x = strs[ i ] ;
            sort( x.begin(), x.end() );
            stra.push_back( x );
            fr[ x ].push_back( i );
        }
        for( auto x:fr ){
            strb = x.second;
            vector< string > strc;
            for( int i = 0 ; i < strb.size() ; i++ ){
                strc.push_back( strs[ strb[i] ] );
            }
            ans.push_back( strc );
        }
        
        return ans;
    }
};
