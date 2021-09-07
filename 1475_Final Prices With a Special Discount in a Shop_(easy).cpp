class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n,0);
        stack< pair<int, int> > st;
        st.push( {prices[0], 0});
        for( int i = 0; i < n; i++ ){
            if( st.empty() ){
                st.push( {prices[i], i} );
                continue;
            }
            while( !st.empty() && st.top().first >= prices[i] ){
                ans[st.top().second] = st.top().first - prices[i];
                st.pop();
            }
            st.push( {prices[i], i} );
        }
        while( !st.empty() ){
            ans[ st.top().second ] = st.top().first;
            st.pop();
        }
        return ans;
    }
};
