class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size(), i = 1;
        stack<char> st;
        st.push( num[0] );
        while( i < n ){
            if( st.empty() && num[i] == '0' ){
                i++;
                continue;
            }
            else if( !st.empty() && num[i] < st.top() && k > 0 ){
                st.pop();
                k--;i--;
            }
            else{
                st.push( num[i] );
            }
            i++;
        }
        while( !st.empty() && k > 0 ){
            st.pop();
            k--;
        }
        if( st.empty() )return "0";
        i = n-1;
        while( !st.empty() ){
            num[i] = st.top();
            st.pop();
            i--;
        }
        return num.substr(i+1);
    }
};
