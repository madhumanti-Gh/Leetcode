class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string key = "", value, ans = "";
        bool f = false;
        int n = s.size(), m = knowledge.size(), c = 0, j = 0;
        map<string, string> mp;
        for( int i = 0; i < m; i++ ){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        for( int i = 0; i < n; i++ ){
            if( s[i] == '(' ){
                f = true;
                c = i;
            }
            else if( s[i] == ')' ){
                if( mp.find(key) != mp.end() ){
                    ans += mp[key];
                }
                else{
                    ans.push_back('?');
                }
                f = false;
                key = "";
            }
            else if( f ){
                key.push_back(s[i]);
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
