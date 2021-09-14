class Solution {
public:
    int firstMissingPositive(vector<int>& arr) {
        int n = arr.size();
        for( long long int i = 0; i < n; i++ ){
            while( arr[i] >=1 && arr[i] <= n && arr[i] != arr[arr[i] - 1] ){
                swap( arr[i], arr[arr[i] - 1] );
            }
        }
        for( long long int i = 0; i < n; i++ ){
            if( arr[i] - 1 != ( i ) ){
                return i+1;
            }
        }
        return n+1;
    }
};
