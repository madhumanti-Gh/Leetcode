class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() -1, j = b.size() -1, carry = 0, temp = 0;
        while( i >= 0 && j >= 0 ){
            if( a[i] == b[j] ){
                temp = 0 +carry;
                ans += (temp + '0');
                carry = ( a[i] - '0' );
            }
            else if( a[i] != b[j] ){
                if( carry == 1 )ans += '0';
                else ans += '1';
            }
            i--;j--;
        }
        while( i >= 0 ){
            if( a[i] == '0' ){
                ans += ( carry + '0' );
                carry = 0;
            }
            else{
                if( carry == 1 )ans += '0';
                else ans += '1';
            }
            i--;
        }
        while( j >= 0 ){
            if( b[j] == '0' ){
                ans += ( carry + '0' );
                carry = 0;
            }
            else{
                if( carry == 1 )ans += '0';
                else ans += '1';
            }
            j--;
        }
        if( carry == 1 )ans += ( carry + '0');
        j = ans.size();
        for( i = 0; i < j/2; i++ ){
            swap( ans[i], ans[j-1-i] );
        }
        return ans;
    }
};
