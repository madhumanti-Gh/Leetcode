class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int C = capacity, i = -1, n = plants.size();
        long long int steps = 0;
        while( i < n-1 ){
            if( plants[i+1] <= C ){
                C -= plants[i+1];
                steps++;
                i++;
            }
            else{
                steps += (i+i+2);
                C = capacity;
            }
        }
        return steps;
    }
};
