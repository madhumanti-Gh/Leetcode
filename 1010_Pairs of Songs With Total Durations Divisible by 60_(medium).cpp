class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size(), i, count = 0;
        int freq[60] ={0};
        for( i = 0; i < n; i++ ){
            freq[time[i]%60]++;
        }
        for( i = 1; i < 30; i++ ){
            count += ( freq[i] * freq[60-i] );
        }
        if( freq[0] > 1 )
            count += ( (freq[0] -1)* freq[0] )/2;
        if( freq[30] > 1 )
            count += ( (freq[30] -1)* freq[30] )/2;
        return count;
    }
};
