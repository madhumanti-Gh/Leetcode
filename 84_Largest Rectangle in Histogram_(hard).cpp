class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), i, len = 0, max_area = 0;
        vector<int> left( n, -1 ), right( n, n );
        
        stack<int> st;
        for( i = 0; i < n; i++ ){
            if( st.empty() || heights[i] >= heights[st.top()] ){
                st.push( i );
                continue;
            }
            while( !st.empty() && heights[i] < heights[st.top()] ){
                right[st.top()] = i;
                st.pop();
            }
            st.push( i );
        }
        while( !st.empty() )st.pop();
        for( i = n-1; i >= 0; i-- ){
            if( st.empty() || heights[i] >= heights[st.top()] ){
                st.push( i );
                continue;
            }
            while( !st.empty() && heights[i] < heights[st.top()] ){
                left[st.top()] = i;
                st.pop();
            }
            st.push( i );
        }
        for( i = 0; i < n; i++ ){
            len = (right[i] - i) + ( i - left[i] ) -1;
            max_area = max( max_area, len*heights[i] );
        }
        return max_area;
    }
};
