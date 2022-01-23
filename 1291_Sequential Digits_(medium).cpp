class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int start = low, digits, mn, mx, num, i, j, end;
        vector<int> ans;
        for( i = 1; i < 9; i++ ){
            start = i;
            j = i+1;
            num = i;
            while( j <= 9 ){
                num = num*10 +j;
                j++;
                if( num >= low && num <= high )ans.push_back( num );
                if( num > high )break;
            }
        }
        sort( ans.begin(), ans.end() );
        return ans;
    }
};
