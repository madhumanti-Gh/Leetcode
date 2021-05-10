class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cnt;
        for(int i=0;i<=num;i++){
            cnt.push_back( __builtin_popcount(i) );
        }
        return cnt;
    }
};
