class Solution {
public:
    vector<vector<int>> ans;
    void SumUp( vector<int>& c, vector<int> store, int idx, int target ){
        if( target == 0 )ans.push_back(store);
        int n = c.size();
        if( target == 0 || idx >= n )return;
        SumUp( c, store, idx+1, target );
        if( c[idx] <= target ){
            store.push_back(c[idx]);
            SumUp( c, store, idx, target - c[idx] );
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> store;
        SumUp( candidates, store, 0, target );
        return ans;
    }
};
