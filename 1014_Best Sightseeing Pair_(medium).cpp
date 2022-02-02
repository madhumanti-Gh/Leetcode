class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), temp, j, max_val = values[0], score = 0;
        for( j = 1; j < n; j++ ){
            temp = values[j] - j;
            score = max( score, max_val + temp );
            max_val = max( max_val, values[j] + j );
        }
        return score;
    }
};
