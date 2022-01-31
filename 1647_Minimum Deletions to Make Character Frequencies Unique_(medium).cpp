class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq( 26, 0 );
        for( char& c : s )freq[c - 'a']++;
        
        priority_queue<int> mxh;
        for( int i = 0; i < 26; i++ ){
            if( freq[i] > 0 ){
                mxh.push( freq[i] );
            }
        }
        
        int cur, ans = 0;
        while( !mxh.empty() && mxh.top() > 0 ){
            cur = mxh.top();
            mxh.pop();
            if( !mxh.empty() && mxh.top() == cur ){
                cur -= 1;
                ans++;
                mxh.push( cur );
            }
        }
        return ans;
    }
};
