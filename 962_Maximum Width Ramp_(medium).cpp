class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int max_width = 0, i = 1, n = nums.size();
        stack<int> st;
        st.push( 0 );
        while( i < n ){
            if( nums[i] <= nums[st.top()] ){
                st.push( i );
            }
            i++;
        }
        i = n-1;
        while( !st.empty() ){
            if( nums[st.top()] <= nums[i] ){
                max_width = max( max_width, i- st.top() );
                st.pop();
            }
            else{
                i--;
            }
        }
        return max_width;
    }
};
