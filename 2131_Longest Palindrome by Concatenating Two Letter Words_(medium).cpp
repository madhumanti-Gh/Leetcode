class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int> freq1, freq2;
        int n = words.size(), len = 0, max_len = 0, odd_freq = 0;
        for( string& word : words ){
            if( word[0] == word[1] )freq1[word]++;
            else freq2[word]++;
        }
        string temp;
        for( auto& word : words ){
            if( freq1[word] > 0 ){
                if( freq1[word]%2 != 0 )odd_freq++;
                max_len += (( freq1[word] /2 ) *4 );
                freq1[word] = 0;
            }
            else if( freq2[word] > 0 ){
                temp = "";
                temp.push_back(word[1]);
                temp.push_back(word[0]);
                len = min( freq2[word], freq2[temp] );
                max_len += ( 4* len );
                freq2[temp] = 0;
                freq2[word] = 0;
            }
        }
        if( odd_freq > 0 )return max_len + 2;
        return max_len;
    }
};
