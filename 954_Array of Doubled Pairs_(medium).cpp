class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n = arr.size(), i, cNeg = 0;
        unordered_map<int, int> freq;
        for( i = 0; i < n; i++ ){
            freq[arr[i]]++;
            if( arr[i] < 0 )cNeg++;
        }
        sort( arr.begin(), arr.end() );
        if( freq[0] > 0 ){
            if( freq[0]%2 == 1 )return false;
        }
        if( cNeg%2 != 0 )return false;
        if( ( n - cNeg - freq[0] )%2 == 1 )return false;
        for( i = cNeg-1; i >= 0; i-- ){
            if( freq[arr[i]] == 0 )continue;
            if( freq[2* arr[i]] > 0 ){
                freq[arr[i]]--;
                freq[2* arr[i]]--;
            }
            else return false;
        }
        for( i = ( cNeg + freq[0] ); i < n; i++ ){
            if( freq[arr[i]] == 0 )continue;
            if( freq[2* arr[i]] > 0 ){
                freq[arr[i]]--;
                freq[2* arr[i]]--;
            }
            else return false;
        }
        return true;
    }
};
