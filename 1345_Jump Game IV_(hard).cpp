class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), i, j, steps = 0, sz, id;
        if( n <= 2 )return n-1;
        map<int, vector<int>> mp;
        for( i = 0; i < n; i++ ){
            mp[arr[i]].push_back( i );
        }
        queue<int> q;
        q.push(0);
        while( !q.empty() ){
            steps++;
            sz = q.size();
            for( i = 0; i < sz; i++ ){
                id = q.front();
                q.pop();
                if( id > 0 && mp.find( arr[id-1] ) != mp.end() )q.push( id-1 );
                if( id < n-1 && mp.find( arr[id+1] ) != mp.end() ){
                    if( id+1 == n-1 )return steps;
                    q.push( id+1 );
                }
                if( mp.find( arr[id] ) != mp.end() ){
                    for( auto& j : mp[arr[id]] ){
                        if( j != id ){
                            if( j == n-1 )return steps;
                            q.push( j );
                        }
                    }
                }
                mp.erase( arr[id] );
            }
        }
        return steps;
    }
};
