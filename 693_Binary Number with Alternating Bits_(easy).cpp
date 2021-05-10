class Solution {
public:
    bool hasAlternatingBits(long long int n) {
        int s = (int)log2(n)+1;
        cout<<s<<endl;
        bool f = true;
        int i;
        long long int y = n;
        if(s%2 == 0){
            for(i=s-1;i>=0;i--){
                cout<<(y)<<" ";
                if(i%2 == 1 && (y&1) == 0){
                    f = true;
                }
                else if(i%2 == 0 && (y&1) == 1){
                    f = true;
                }
                else{
                    f = false;break;
                }
                y = (y>>1);
            }
        }
        if(s%2 == 1){
            for(i=s-1;i>=0;i--){
                cout<<(y&1)<<" ";
                if(i%2 == 0 && (y&1) == 1){
                    f = true;
                }
                else if(i%2 == 1 && (y&1) == 0){
                    f = true;
                }
                else{
                    f = false;break;
                }
                y = (y>>1);
            }
        }
        return f;
    }
};
