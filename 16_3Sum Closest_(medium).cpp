class Solution {
public:
    int threeSumClosest(vector<int>& A, int B) {
        int i,l,r,C,n = A.size();
	sort( A.begin(), A.end() );
	int temp, diff = 1e8;
	int x,y,z;
	for( i = 0; i < n-2; i++ ){
		l = i+1;
		r = n-1;
		C = B - A[i];
		while( l < r ){
			temp = A[i] + A[l] + A[r];
			if( diff > abs( B - temp ) ){
				diff = min( diff, abs(B - temp) );
				x = i;y = l;z = r;
			}
			if( A[l] + A[r] == C ){
				diff = 0;
				x = i;y = l;z = r;
				break;
			}
			else if( A[l] + A[r] > C ){
				r--;
			}
			else if( A[l] + A[r] < C ){
				l++;
			}
		}
		if( diff == 0 )break;
	}
	return A[x]+A[y]+A[z];
    }
};
