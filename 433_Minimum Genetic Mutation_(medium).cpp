class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int n = bank.size(), i, j, k;
        if( start == end )return 0;
        bool Present = false;
        for( i = 0; i < n; i++ ){
            if( bank[i] == end )Present = true;
            if( bank[i] == start )bank[i] = "0";
        }
        if( !Present )return -1;
        
        char genes[4] = {'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push( start );
        string cur, temp;
        int depth = 0, length, len;
        while( !q.empty() ){
            depth++;
            length = q.size();
            while( length-- ){
                cur = q.front();
                q.pop();
                len = cur.size();
                for( i = 0; i < len; i++ ){
                    temp = cur;
                    for( j = 0; j < 4; j++ ){
                        if( genes[j] == cur[i] )continue;
                        temp[i] = genes[j];
                        if( temp == end )return depth;
                        for( k = 0; k < n; k++ ){
                            if( bank[k] == temp ){
                                bank[k] = "0";
                                q.push( temp );
                                break;
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};
