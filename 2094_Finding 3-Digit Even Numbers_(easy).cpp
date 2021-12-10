class Solution {
private:
    bool check( int n, vector<int> freq ){
        int d;
        while( n > 0 ){
            d = n%10;
            freq[d]--;
            if( freq[d] < 0 )return false;
            n /= 10;
        }
        return true;
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        int n = digits.size(), i;
        for( auto i: digits )freq[i]++;
        vector<int> ans;
        for( i = 100; i < 999; i += 2 ){
            if( check(i, freq) )ans.push_back(i);
        }
        return ans;
    }
};
