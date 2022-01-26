class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size(), i;
        if( n <= 2 )return false;
        if( arr[1] <= arr[0] )return false;
        bool flag = false;
        for( i = 2; i < n; i++ ){
            if( arr[i] == arr[i-1] )return false;
            if( !flag ){
                if( arr[i] < arr[i-1] )flag = true;
            }
            else if( flag ){
                if( arr[i] > arr[i-1] )return false;
            }
        }
        if( !flag )return false;
        return true;
    }
};
