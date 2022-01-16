class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i, n = seats.size(), gap = 0, maxDist = 0, start = -1, end = 0;
        for( i = 0; i <= n; i++ ){
            if( i == n || seats[i] == 1 ){
                gap = (i-start)/2;
                if( start == -1 || i == n )gap = (i - start -1);
                maxDist = max( maxDist, gap );
                start = i;
            }
        }
        return maxDist;
    }
};
