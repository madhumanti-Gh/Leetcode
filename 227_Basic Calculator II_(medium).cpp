// Using Stack [ O(n) space ]
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.size(), i, cur_num = 0, temp;
        char cur, Operator = '+';
        for( i = 0; i < n; i++ ){
            cur = s[i];
            if( cur >= '0' && cur <= '9' ){
                cur_num = (cur_num * 10) + (cur - '0');
            }
            if( cur == '+' || cur == '-' || cur == '*' || cur == '/' || i == n-1 ){
                if( Operator == '-' ){
                    st.push( - cur_num );
                }
                else if( Operator == '+' ){
                    st.push( cur_num );
                }
                else if( Operator == '*' ){
                    temp = st.top();
                    st.pop();
                    st.push( temp * cur_num );
                }
                else if( Operator == '/' ){
                    temp = st.top();
                    st.pop();
                    st.push( temp / cur_num );
                }
                Operator = cur;
                cur_num = 0;
            }
        }
        int ans = 0;
        while( !st.empty() ){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

// Without Stack [ O(1) space ]
class Solution {
public:
    int calculate(string s) {
        int n = s.size(), i, cur_num = 0, temp, ans = 0, prev_num = 0;
        char cur, Operator = '+';
        for( i = 0; i < n; i++ ){
            cur = s[i];
            if( cur >= '0' && cur <= '9' ){
                cur_num = (cur_num * 10) + (cur - '0');
            }
            if( cur == '+' || cur == '-' || cur == '*' || cur == '/' || i == n-1 ){
                if( Operator == '+' ){
                    ans += prev_num;
                    prev_num = cur_num;
                }
                else if( Operator == '-' ){
                    ans += prev_num;
                    prev_num = - cur_num;
                }
                else if( Operator == '*' ){
                    prev_num = prev_num * cur_num;
                }
                else if( Operator == '/' ){
                    prev_num = prev_num / cur_num;
                }
                Operator = cur;
                cur_num = 0;
            }
        }
        return ans + prev_num;
    }
};
