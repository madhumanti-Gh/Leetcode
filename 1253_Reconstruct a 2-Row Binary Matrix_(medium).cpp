class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans;
        int n = colsum.size(), i;
        vector<int> c0(n,0), c1(n,0);
        for( i = 0; i < n; i++ ){
            if( colsum[i] == 2 ){
                c0[i] = 1;
                upper--;
                c1[i] = 1;
                lower--;
            }
        }
        for( i = 0; i < n; i++ ){
            if( colsum[i] == 1 ){
                if( upper > 0 ){
                    c0[i] = 1;
                    upper--;
                }
                else if( lower > 0 ){
                    c1[i] = 1;
                    lower--;
                }
                else return ans;
            }
        }
        if( upper != 0 || lower != 0 )return ans;
        ans.push_back(c0);
        ans.push_back(c1);
        return ans;
    }
};
