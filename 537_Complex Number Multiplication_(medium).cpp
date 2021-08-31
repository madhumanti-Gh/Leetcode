class Solution {
public:
    pair<int, int> findNum(string num){
        int a,b,j = 0,base,n = num.size() - 1;
        bool flag = true,neg = false;
        b = 0;a = 1;
        base = 10;
        if( num[0] == '-' ){
            a *= (-1);
            j = 1;
        }
        for( int i = j; i < n; i++ ){
            if( num[i] == '-' ){
                neg = true;
            }
            if( num[i]>= 48 && num[i] <= 57 ){
                b = (b*base ) + (num[i] - 48);
            }
            else if( flag ){
                a = a * b;
                flag = false;
                b = 0;
            }
        }
        if( neg )b = (-1)*b;
        return {a,b};
    }
    
    string complexNumberMultiply(string num1, string num2) {
        int a,b,c,d;
        bool flag = true;
        pair<int, int> A,B;
        A = findNum( num1 );
        B = findNum( num2 );
        a = A.first * B.first;
        a -= A.second * B.second;
        b = A.first * B.second;
        b += B.first * A.second;
        string ans = "";
        string e = to_string(a);
        ans = ans + e;
        ans.push_back('+');
        e = to_string(b);
        ans = ans + e;
        ans.push_back('i');
        return ans;
    }
};
