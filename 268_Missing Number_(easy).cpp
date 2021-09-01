class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int i = 1, n = arr.size();
        int expected = n ^ 0;
        int got = arr[0];
        while( i < n){
            expected ^= i;
            got ^= arr[i];
            i++;
        }
        return expected^got;
    }
};
