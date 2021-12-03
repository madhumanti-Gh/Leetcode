class Solution {
public:
    void SumUp( vector<int>& c, vector<int>& store, int idx, int target, vector<vector<int>>& ans ){
        if( target == 0 ){
            ans.push_back(store);
            return;
        }
        for( int i = idx; i < c.size(); i++ ){
            if( i > idx && c[i] == c[i-1] )continue;
            if( c[i] > target )break;
            store.push_back( c[i] );
            SumUp( c, store, i+1, target -c[i], ans );
            store.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort( candidates.begin(), candidates.end() );
        vector<int> store;
        int n = candidates.size();
        vector<vector<int>> ans;
        SumUp( candidates, store, 0, target, ans );
        return ans;
    }
};
