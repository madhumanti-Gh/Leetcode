class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0, n = num1.size(), m = num2.size(), i = n-1, j = m-1, k, rem = 0;
        string ans;
        if( n > m )ans = num1;
        else ans = num2;
        k = ans.size() -1;
        while( i >= 0 && j >= 0 ){
            carry += (num1[i] - '0') + (num2[j] - '0');
            rem = carry%10;
            carry /= 10;
            ans[k] = (char)(rem+48);
            k--;i--;j--;
        }
        while( i >= 0 ){
            carry += (num1[i] - '0');
            rem = carry%10;
            carry /= 10;
            if( k < 0 ){
                ans = to_string(rem+48) + ans;
            }
            else{
                ans[k] = (char)(rem+48);
                k--;
            }
            i--;
        }
        while( j >= 0 ){
            carry += (num2[j] - '0');
            rem = carry%10;
            carry /= 10;
            if( k < 0 ){
                ans = to_string(rem+48) + ans;
            }
            else{
                ans[k] = (char)(rem+48);
                k--;
            }
            j--;
        }
        while( carry > 0 ){
            rem = carry%10;
            carry /= 10;
            if( k < 0 ){
                ans = to_string(rem) + ans;
            }
            else{
                ans[k] = (char)(rem+48);
                k--;
            }
        }
        return ans;
    }
};
