class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp, prev;
        int i, row, len = 0;
        prev.push_back({ 1 });
        for( row = 1; row <= rowIndex; row++ ){
            temp.push_back(1);
            for( i = 1; i <= len; i++ ){
                temp.push_back( prev[i] + prev[i-1] );
            }
            temp.push_back(1);
            prev = temp;
            len++;
            temp.clear();
        }
        return prev;
    }
};
