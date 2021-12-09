class Solution {
public:
    bool findO( vector<int>& arr, int n, int i, vector<int>& vis ){
        if( i >= n || i < 0 || vis[i] == true )return false;
        if( arr[i] == 0 )return true;
        vis[i] = true;
        bool A, B;
        A = findO( arr, n, i+arr[i], vis );
        B = findO( arr, n, i-arr[i], vis );
        return A||B;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, false);
        return findO( arr, n, start, vis );
    }
};
