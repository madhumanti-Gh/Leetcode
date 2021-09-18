class Solution {
public:
    int findComplement(int num) {
        int comp = 0;
        int shift = 0;
        while( num > 0 ){
            int temp = (num & 1);
            if( temp == 0 )comp |= (1<<shift);
            shift++;
            num >>= 1;
        }
        return comp;
    }
};
