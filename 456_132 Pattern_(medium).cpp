class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), i, prev = INT_MIN;
        stack<int> st;
        for( i = n-1; i >= 0; i-- ){
            if( nums[i] < prev )return true;
            while( !st.empty() && st.top() < nums[i] ){
                prev = max( prev, st.top() );
                st.pop();
            }
            st.push( nums[i] );
        }
        return false;
    }
};
