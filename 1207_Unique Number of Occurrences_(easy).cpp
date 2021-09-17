class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;
        set<int> st;
        for( int i = 0; i < n; i++ ){
            mp[arr[i]]++;
        }
        for( int i = 0; i < n; i++ ){
            st.insert(mp[arr[i]]);
        }
        if( mp.size() == st.size() )return true;
        return false;
    }
};
