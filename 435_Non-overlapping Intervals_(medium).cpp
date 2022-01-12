class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), count = 0, right = 1, left = 0;
        sort( intervals.begin(), intervals.end() );
        while( right < n ){
            if( intervals[left][1] <= intervals[right][0] ){
                left = right;
                right++;
            }
            else if( intervals[left][1] <= intervals[right][1] ){
                count++;
                right++;
            }
            else if( intervals[left][1] > intervals[right][1] ){
                count++;
                left = right;
                right++;
            }
        }
        return count;
    }
};
