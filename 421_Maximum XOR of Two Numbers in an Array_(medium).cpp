class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0, mask = 0, i, temp;
        for( i = 30; i >= 0; i-- ){
            mask = mask | ( 1<<i );
            set<int> st;
            for( auto& num : nums )st.insert( num & mask );
            temp = ans | ( 1<<i );
            for( int ele : st ){
                if( st.find( temp ^ ele ) != st.end() ){
                    ans = temp;
                    break;
                }
            }
        }
        return ans;
    }
};
