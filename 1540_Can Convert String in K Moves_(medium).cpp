class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        unordered_map<int, int> mp;
        int n = s.size(), i, rem, freq;
        if( t.size() != n )return false;
        for( i = 0; i < n; i++ ){
            if( s[i] == t[i] )continue;
            rem = ( t[i] - s[i] + 26)%26;
            mp[rem]++;
        }
        for( auto& x : mp ){
            rem = x.first;
            freq = x.second;
            if( ( freq-1 )*26 + rem > k )return false;
        }
        return true;
    }
};
// Explained here-> (https://leetcode.com/problems/can-convert-string-in-k-moves/discuss/1707045/easy-explained-solution-using-map)
