class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        while(true){
            int num = 0;
            while( n ){
                num += (n%10) *(n%10);
                n /= 10;
            }
            if( num == 1 )return true;
            if(s.find(num) != s.end() ){
                return false;
            }
            else{
                s.insert(num);
            }
            n = num;
        }
        return true;
    }
};
