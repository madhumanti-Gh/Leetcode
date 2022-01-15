class Solution { 
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), i, cur, range = 0;
        if( s[n-1] != '0' )return false;
        queue<int> q;
        q.push(0);
        while( !q.empty() ){
            cur = q.front();
            q.pop();
            if( cur == n-1 )return true;
            for( i = max( cur+minJump, range ); i <= min( cur+maxJump, n-1 ); i++ ){
                if( s[i] == '0' )q.push(i);
            }
            range = min( cur+maxJump+1, n );
        }
        return false;
    }
};
