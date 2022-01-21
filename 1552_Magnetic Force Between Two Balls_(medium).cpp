class Solution {
private:
    bool distribution(vector<int>& pos, int& gap, int& m){
        int start = pos[0], n = pos.size(), count = 1, i;
        for( i = 0; i < n; i++ ){
            if( start + gap <= pos[i] ){
                count++;
                start = pos[i];
            }
        }
        return count >= m;
    }
public:
    int maxDistance(vector<int>& pos, int m) {
        sort( pos.begin(), pos.end() );
        int n = pos.size(), i, left = 1, right = pos[n-1] - pos[0], mid;
        
        while( left <= right ){
            int mid = left + ( right - left )/2;
            if( distribution( pos, mid, m ) ){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return left-1;
    }
};
