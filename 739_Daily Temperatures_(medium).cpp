class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack< pair<int, int> > st;
        st.push( {temperatures[0], 0} );
        for( int i = 0; i < n; i++ ){
            if( st.empty() ){
                st.push( {temperatures[i], i} );
                continue;
            }
            while( !st.empty() && st.top().first < temperatures[i] ){
                ans[ st.top().second ] = i- st.top().second;
                st.pop();
            }
            st.push( {temperatures[i], i} );
        }
        return ans;
    }
};
