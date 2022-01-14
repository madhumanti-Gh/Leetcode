class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        int i, row = 1, len = 0;
        ans.push_back({ 1 });
        for( row = 1; row < numRows; row++ ){
            temp.push_back(1);
            for( i = 1; i <= len; i++ ){
                temp.push_back( ans[row-1][i] + ans[row-1][i-1] );
            }
            temp.push_back(1);
            ans.push_back(temp);
            len++;
            temp.clear();
        }
        return ans;
    }
};
