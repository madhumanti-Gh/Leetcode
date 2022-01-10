// Using Recursion
class Solution {
private:
    long find_ans( string& s, int& id ){
        long ans = 0, num;
        int n = s.size(), i;
        bool neg = false;
        while( id < n && s[id] != ')' ){
            if( s[id] == '+' || s[id] == ' ' )id++;
            else if( s[id] == '-' ){
                id++;
                neg = true;
            }
            else if( s[id] == '(' ){
                id++;
                if( neg )ans -= find_ans( s, id );
                else ans += find_ans( s, id );
                neg = false;
            }
            else{
                num = 0;
                while( id < n && isdigit( s[id] ) ){
                    num = num *10 + ( s[id] - '0' );
                    id++;
                }
                if( neg )ans -= num;
                else ans += num;
                neg = false;
            }
        }
        id++;
        return ans;
    }
public:
    int calculate(string s) {
        int id = 0;
        return find_ans( s,id );
    }
};

// Using stack
class Solution {
public:
    int calculate(string s) {
        long ans = 0, num, temp;
        int n = s.size(), i;
        bool neg = false;
        stack<int> numbers;
        stack<bool> op;
        for( i = 0; i < n; i++ ){
            if( isdigit( s[i] ) ){
                num = 0;
                while( i < n && s[i] >= '0' && s[i] <= '9' ){
                    num = num *10 + ( s[i] - '0' );
                    i++;
                }
                if( neg )ans -= num;
                else ans += num;
                i--;
            }
            else{
                if( s[i] == '+' )neg = false;
                else if( s[i] == '-' )neg = true;
                else if( s[i] == '(' ){
                    numbers.push( ans );
                    ans = 0;
                    op.push( neg );
                    neg = false;
                }
                else if( s[i] == ')' ){
                    if( op.top() == false )ans += numbers.top();
                    else ans = numbers.top() - ans;
                    op.pop();
                    numbers.pop();
                }
            }
        }
        return ans;
    }
};
