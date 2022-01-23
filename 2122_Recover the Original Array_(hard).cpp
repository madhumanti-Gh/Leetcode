class Solution {
private:
    bool findOrg( multiset<int> st, int k, vector<int>& ans ){
        int cur, curHigh;
        while( !st.empty() ){
            cur = *st.begin();
            curHigh = cur + 2*k;
            auto it = st.find( curHigh );
            if( it == st.end() )return false;
            ans.push_back( cur + k );
            st.erase( st.begin() );
            st.erase( it );
        }
        return true;
    }
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        multiset<int> st( nums.begin(), nums.end() );
        int n = nums.size(), i, lowest = nums[0], highest, k;
        
        for( i = 1; i < n; i++ ){
            highest = nums[i];
            if( highest <= lowest || highest%2 != lowest%2 )continue;
            k = ( highest - lowest )/2;
            vector<int> ans;
            if( findOrg( st, k, ans ) )return ans;
        }
        return {};
    }
};
