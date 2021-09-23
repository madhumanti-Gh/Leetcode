class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> mp;
        string fst = "qwertyuiop";
        string snd = "asdfghjkl";
        string trd = "zxcvbnm";
        for( int i = 0; i < fst.size(); i++ ){
            mp[fst[i]] = 1;
            mp[fst[i]-32] = 1;
        }
        for( int i = 0; i < snd.size(); i++ ){
            mp[snd[i]] = 2;
            mp[snd[i]-32] = 2;
        }
        for( int i = 0; i < trd.size(); i++ ){
            mp[trd[i]] = 3;
            mp[trd[i]-32] = 3;
        }
        int n = words.size();
        vector<string> result;
        for( int i = 0; i < n; i++ ){
            int j = 1, prev = mp[words[i][0]], m = words[i].size();
            bool f = true;
            while( j < m ){
                if( prev != mp[words[i][j]] ){
                    f = false;
                    break;
                }
                prev = mp[words[i][j]];j++;
            }
            if( f )result.push_back(words[i]);
        }
        return result;
    }
};
