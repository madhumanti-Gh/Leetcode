class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size(), i, cA = capacityA, cB = capacityB, count = 0;
        for( i = 0; i < n/2; i++ ){
            if( cA < plants[i] ){
                count++;
                cA = capacityA;
            }
            cA -= plants[i];
            if( cB < plants[n-1-i] ){
                count++;
                cB = capacityB;
            }
            cB -= plants[n-1-i];
        }
        if( n%2 == 1 ){
            if( max( cA, cB ) < plants[n/2] )count++;
        }
        return count;
    }
};
