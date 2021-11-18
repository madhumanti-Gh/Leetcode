class Solution {
public:
    int minOperations(int n) {
        int i = 1, op = 0;
        
        while( i < n ){
            op += (n-i);
            i += 2;
        }
        return op;
    }
};

// Another approach
class Solution {
public:
    int minOperations(int n) {
        int mid = n/2;
        if( n%2 == 0 ){
            return (mid*mid);
        }
        else{
            return (mid+1)*mid;
        }
        return 0;
    }
};
