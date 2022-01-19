class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), i;
        
        bool Present = false;
        set<string> words;
        for( i = 0; i < n; i++ ){
            words.insert( wordList[i] );
            if( wordList[i] == endWord )Present = true;
        }
        if( !Present )return 0;
        
        queue<string> q;
        q.push( beginWord );
        int depth = 0, length, len;
        string cur, temp;
        while( !q.empty() ){
            length = q.size();
            depth++;
            while( length-- ){
                cur = q.front();
                q.pop();
                len = cur.size();
                for( i = 0; i < len; i++ ){
                    temp = cur;
                    for( char j = 'a'; j <= 'z'; j+= 1 ){
                        if( j == cur[i] )continue;
                        temp[i] = j;
                        if( temp == endWord )return depth+1;
                        else if( words.find( temp ) != words.end() ){
                            q.push( temp );
                            words.erase( temp );
                        }
                    }
                }
            }
        }
        return 0;
    }
};
