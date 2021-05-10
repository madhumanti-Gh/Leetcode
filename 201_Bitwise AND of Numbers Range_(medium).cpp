class Solution {
public:
    int rangeBitwiseAnd(long long int left, long long int right) {
        long long int base = 1;
        long long int l=0,r=0;
        if(left == right){
            return left;
        }
        for(int i=0;i<=31;i++){
            if(left >= base){
                l = base;
            }
            if(right < base){
                r = base/2;
                break;
            }
            base = base* 2;
        }
        if(l == 0 || l != r){
            return 0;
        }
        else{
            long long int ans = left;
            for(long long int i=left+1;i<=right;i++){
                ans = ans&i;
                if(ans == 0){
                    break;
                }
            }
            return ans;
        }
    }
};
