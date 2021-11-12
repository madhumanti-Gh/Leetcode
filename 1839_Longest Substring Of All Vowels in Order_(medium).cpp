class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int l = 0, r = 0, n = word.size();
        if( n < 5 )return 0;
        int c = 0, maxc = 0;
        char x = 'a';
        while( l <= r && r < n ){
            if( word[l] != 'a' ){
                l++;r++;
                continue;
            }
            else if( x == 'a' && ( word[r] == 'a' || word[r] == 'e' ) ){
                c++;
                x = word[r];
                r++;
            }
            else if( x == 'e' && ( word[r] == 'e' || word[r] == 'i' ) ){
                c++;
                x = word[r];
                r++;
            }
            else if( x == 'i' && ( word[r] == 'i' || word[r] == 'o' ) ){
                c++;
                x = word[r];
                r++;
            }
            else if( x == 'o' && ( word[r] == 'o' || word[r] == 'u' ) ){
                c++;
                x = word[r];
                if( word[r] == 'u' ){
                    maxc = max( c, maxc );
                }
                r++;
            }
            else if( x == 'u' ){
                if( word[r] == 'u' ){
                    c++;
                    x = word[r];
                    r++;
                    maxc = max( c, maxc );
                }
                else{
                    x = 'a';c = 0;
                    l = r;
                }
            }
            else{
                x = 'a';c = 0;l = r;
            }
        }
        return maxc;
    }
};
