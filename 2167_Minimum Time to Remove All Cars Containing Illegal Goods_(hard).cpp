class Solution {
public:
	// Using Kadane's Algorithm
    int minimumTime(string s) {
        int n = s.size(), i, sum = 0, min_sum = 0;
        
        for( i = 0; i < n; i++ ){
            if( s[i] == '0' )sum--;
            else sum++;
            min_sum = min( min_sum, sum );
            if( sum > 0 )sum = 0;
        }
        return n + min_sum;
    }
};
