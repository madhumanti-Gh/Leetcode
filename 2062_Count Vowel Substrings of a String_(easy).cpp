class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.size();
        if( n < 5 )return 0;
        int count = 0;
        map<char, int> freq;
        for( int i = 0; i < n; i++ ){
            for( int j = i; j < n; j++ ){
                
                if( word[j] == 'a' || word[j] == 'e'|| word[j] == 'i' || word[j] == 'o' || word[j] == 'u' ){
                    freq[word[j]]++;
                }
                else{
                    break;
                }
                if( freq['a'] > 0 && freq['e'] > 0 && freq['i'] > 0 && freq['o'] > 0 && freq['u'] > 0 ){
                    count++;
                }
            }
            freq['a'] = 0;
            freq['e'] = 0;
            freq['i'] = 0;
            freq['o'] = 0;
            freq['u'] = 0;
        }
        return count;
    }
};
