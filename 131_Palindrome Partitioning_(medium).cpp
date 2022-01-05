class Solution {
private:
    bool isPalindrome( string s, int start, int end ){
        while( start <= end ){
            if( s[start] != s[end] )return false;
            start++;end--;
        }
        return true;
    }
    void parting( int id, vector<vector<string>>& ans, vector<string>& vec, string& s ){
        int n = s.size(), i;
        if( id == n ){
            ans.push_back( vec );
            return;
        }
        for( i = id; i < n; i++ ){
            if( isPalindrome( s, id, i ) ){
                vec.push_back( s.substr( id, i-id+1 ) );
                parting( i+1, ans, vec, s );
                vec.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        parting( 0, ans, temp, s );
        return ans;
    }
};
