class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), i, j = 0, k = 0, presum = 0;
        for( i = 0; i < n; i++ ){
            gas[i] -= cost[i];
            presum += gas[i];
            if( presum < 0 ){
                presum = 0;
                j = i+1;
                k = i+1;
            }
            else k++;
        }
        if( presum < 0 )return -1;
        k = 0;
        while( k < j ){
            presum += gas[k];
            if( presum < 0 )return -1;
            k++;
        }
        if( presum >= 0 )return j;
        return -1;
    }
};
