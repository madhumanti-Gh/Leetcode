class Solution {
public:
    static bool compare( int num1, int num2 ){
        string str1 = to_string(num1), str2 = to_string(num2);
        if( str1+str2 > str2+str1 )return true;
        else return false;
    }
    string largestNumber(vector<int>& nums) {
        int i, j, n = nums.size();
        sort( nums.begin(), nums.end(), compare );
        if( nums[0] == 0 )return "0";
        string ans = "";
        for( i = 0; i < n; i++ ){
            ans += to_string( nums[i] );
        }
        return ans;
    }
};
