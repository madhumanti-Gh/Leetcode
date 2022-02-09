class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int n = milestones.size(), i;
        sort( milestones.begin(), milestones.end() );
        long long sum = 0, mx = milestones[n-1];
        for( i = 0; i < n-1; i++ ){
            sum += milestones[i];
        }
        if( sum >= mx )return sum + mx;
        return ( sum + sum + 1 );
    }
};
