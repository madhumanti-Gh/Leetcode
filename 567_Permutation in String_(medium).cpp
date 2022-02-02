class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size(), i;
        if( n > m )return false;
        
        vector<int> freqS2( 26, 0 );
        vector<int> freqS1( 26, 0 );
        
        for( i = 0; i < n; i++ ){
            freqS1[s1[i] - 'a']++;
            freqS2[s2[i] - 'a']++;
        }
        if( freqS1 == freqS2 )return true;
        
        for( i = n; i < m; i++ ){
            freqS2[s2[i-n] - 'a']--;
            freqS2[s2[i] - 'a']++;
            if( freqS1 == freqS2 )return true;
        }
        return false;
    }
};
