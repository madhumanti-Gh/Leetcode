class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size(), i;
        vector<long long> ans(n, 0);
        unordered_map<int, long long> cntId, sumId;
        for( i = 0; i < n; i++ ){
            if( cntId[arr[i]] > 0 )ans[i] += ( ( cntId[arr[i]] * i * 1LL ) - sumId[arr[i]] );
            sumId[arr[i]] += i;
            cntId[arr[i]]++;
        }
        sumId.clear();
        cntId.clear();
        for( i = n-1; i >= 0; i-- ){
            if( cntId[arr[i]] > 0 )ans[i] += ( sumId[arr[i]] - ( cntId[arr[i]] * i * 1LL ) );
            sumId[arr[i]] += i;
            cntId[arr[i]]++;
        }
        return ans;
    }
};
