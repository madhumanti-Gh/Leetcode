class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for( int i = 0; i < n; i++ ){
            if( st.empty() || ( st.top() < 0 && asteroids[i] < 0 ) || ( st.top() > 0 && asteroids[i] > 0 ) ){
                st.push( asteroids[i] );
            }
            else if( asteroids[i] < 0 && st.top() > 0 ){
                if( st.top() < abs( asteroids[i] ) ){
                    st.pop();i--;
                }
                else if( st.top() == abs( asteroids[i] ) ){
                    st.pop();
                }
            }
            else{
                st.push(asteroids[i]);
            }
        }
        int sz = st.size();
        vector<int> ans(sz,0);
        for( int i = sz-1; i >= 0; i-- ){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
