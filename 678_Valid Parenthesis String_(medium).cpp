class Solution {
public:
    bool checkValidString(string s) {
        int i, n = s.size();
        stack<int> bracket, star;
        for( i = 0; i < n; i++ ){
            if( s[i] == '(' )bracket.push(i);
            else if( s[i] == '*' )star.push(i);
            else if( s[i] == ')' ){
                if( bracket.size() > 0 )bracket.pop();
                else if( star.size() > 0 )star.pop();
                else return false;
            }
        }
        while( bracket.size() > 0 ){
            if( star.size() > 0 && star.top() > bracket.top() ){
                bracket.pop();
                star.pop();
            }
            else return false;
        }
        return true;
    }
};
