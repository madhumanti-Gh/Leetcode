class Solution {
public:
    static bool comparator( string a, string b ){
        return a.size() < b.size();
    }
    int longestStrChain( vector<string>& words ){
        sort( words.begin(), words.end(), comparator );
        
        int arr_len = words.size(), str_len, res = 0;
        string temp;
        map<string, int> mp;
        
        for( string word : words ){
            str_len = word.size();
            mp[word] = 1;
            for( int i = 0; i < str_len; i++ ){
                if( i == 0 )temp = word.substr(1);
                else if( i == str_len -1 )temp = word.substr( 0, str_len-1 );
                else temp = word.substr( 0, i ) + word.substr( i+1 );
                
                if( mp.find(temp) != mp.end() ){
                    mp[word] = max( mp[temp]+1, mp[word] );
                }
            }
            res = max( res, mp[word] );
        }
        return res;
    }
};
