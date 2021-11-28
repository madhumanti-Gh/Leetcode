class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size(), carry = 0, i = n-1, count = 0;
        while( k > 0 && i >= 0 ){
            carry += (k%10) + num[i];
            num[i] = carry%10;
            k /= 10; carry /= 10;
            i--;
        }
        while( i >= 0 && carry > 0 ){
            carry += num[i];
            num[i] = carry%10;
            carry /= 10;
            i--;
        }
        int temp1 = carry, temp2 = k;
        while( temp1 > 0 || temp2 > 0 ){
            temp1 += (temp2%10);
            count++;
            num.push_back(0);
            temp1 /= 10;
            temp2 /= 10;
        }
        i = 1;
        while( n >= i ){
            num[num.size() - i] = num[n-i];
            i++;
        }
        temp1 = carry, temp2 = k, i = num.size() - n -1;
        while( temp1 > 0 || temp2 > 0 ){
            temp1 += (temp2%10);
            num[i] = temp1%10;
            i--;
            temp1 /= 10;
            temp2 /= 10;
        }
        return num;
    }
};
