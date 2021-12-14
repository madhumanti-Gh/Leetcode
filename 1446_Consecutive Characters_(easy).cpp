class Solution {
public:
    int maxPower(string s) {
        int n = s.size(), i, count = 1, j, power = 0;
        if( n == 1 )return n;
        char target = s[0];
        i = 0;
        j = 1;
        while( i < j && j < n ){
            if( s[j] != target ){
                target = s[j];
                i = j;
                power = max( power, count );
                count = 1;
            }
            else count++;
            // cout<<count<<" "<<s[j]<<"\n";
            j++;
        }
        power = max( power, count );
        return power;
    }
};
