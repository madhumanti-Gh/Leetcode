class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        int temp,sum = 0;
        for( int i = 0; i < n; i++ ){
            temp = s[i] - 'a' + 1;
            sum += (temp%10);
            temp /= 10;
            sum += (temp%10);
        }
        k--;
        while(k--){
            temp = sum;
            sum = 0;
            while(temp){
                sum += (temp%10);
                temp /= 10;
            }
        }
        cout<<sum<<"\n";
        return sum;
    }
};
