class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        vector<int> cur(2,0);
        int i = 0, j = 0, n = firstList.size(), m = secondList.size();
        while( i < n && j < m ){
            if( firstList[i][0] <= secondList[j][1] && firstList[i][1] >= secondList[j][0] ){
                cur[0] = max( firstList[i][0], secondList[j][0] );    // 8
                cur[1] = min( firstList[i][1], secondList[j][1] );    // 10
                if( cur[1] == firstList[i][1] )i++;
                if( cur[1] == secondList[j][1] )j++;
                ans.push_back( cur );
            }
            else if( firstList[i][1] > secondList[j][1] )j++;
            else i++;
        }
        return ans;
    }
};
