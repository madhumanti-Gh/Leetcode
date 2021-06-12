class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        
        if( len1 == 0 || len2 == 0 )return "0";
        
        vector<int> res( len1 + len2, 0 );
        
        int id1 = 0,id2 = 0;
        for( int i = len1 - 1; i >= 0; i-- ){
            int carry = 0;
            id2 = 0;
            int n1 = num1[i] - '0';
            for( int j = len2 - 1; j >= 0; j-- ){
                int n2 = num2[j] - '0';
                int sum = n1 * n2 + res[ id1 + id2 ] + carry;
                carry = sum/10;
                res[ id1 + id2 ] = sum%10;
                id2++;
            }
            if( carry > 0 ){
                res[ id1 + id2 ] += carry;
            }
            id1++;
        }
        
        int sz = res.size() - 1;
        while( sz >= 0 && res[sz] == 0 )sz--;
        
        if( sz == -1 )return "0";
        
        string num = "";
        while( sz >= 0 ){
            num += to_string( res[sz--] );
        }
        return num;
    }
};
