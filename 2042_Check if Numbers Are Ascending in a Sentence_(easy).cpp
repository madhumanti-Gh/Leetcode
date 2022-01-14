class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.size(), i = 0, num = 0, prev = 0;
        while( i < n ){
            if( isdigit( s[i] ) ){
                num = 0;
                while( i < n && isdigit( s[i] ) ){
                    num = num*10 + ( s[i] - '0');
                    i++;
                }
                if( num <= prev )return false;
                else prev = num;
            }
            i++;
        }
        return true;
    }
};
