class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> st;
        string str = "", temp;
        int num = 0, i, n = s.size(), freq;
        for( i = 0; i < n; i++ ){
            if( s[i] >= '0' && s[i] <= '9' ){
                num = num*10 + ( s[i] - '0' );
            }
            else if( s[i] == '[' ){
                st.push( str );
                str = "";
                nums.push( num );
                num = 0;
            }
            else if( s[i] == ']' ){
                temp = str;
                str = st.top();
                st.pop();
                freq = nums.top();
                nums.pop();
                while( freq-- )str += temp;
            }
            else str.push_back( s[i] );
        }
        return str;
    }
};
