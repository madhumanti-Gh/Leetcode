class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int S = s.size();
        int P = p.size();
        vector<int> idx;
        if( S < P ){
            return idx;
        }
        int x,y;
        int freqp[26] = {0};
        int freqs[26] = {0};
        for(int i=0;i<P;i++){
            x = p[i] - 'a';
            y = s[i] - 'a';
            freqp[x]++;
            freqs[y]++;
        }
        for(int i=0; i <= (S-P); i++ ){
            bool f = true;
            for( int j = 0; j < 26 ; j++ ){
                if( freqp[j] != freqs[j] ){
                    f = false;break;
                }
            }
            if(f){
                idx.push_back(i);
            }
            x = s[i] - 'a';
            y = s[i+P] - 'a';
            freqs[x]--;
            if( i < S-P ){
                freqs[y]++;
            }
        }
        
        return idx;
    }
};
