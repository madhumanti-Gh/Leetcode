class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size(), i;
        unordered_map<char, int> freq;
        for( char& c : s )freq[c]++;
        int odd = 0, length = 0;
        for( auto& c : freq ){
            if( c.second%2 == 0 )length += c.second;
            else{
                length += ( (c.second/2) * 2);
                odd++;
            }
        }
        if( odd > 0 )return length + 1;
        return length;
    }
};
