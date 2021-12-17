class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int i, sz;
        if( n == 1 )return {0};
        vector<vector<int>> adj(n);
        vector<int> neigh(n,0);
        for( i = 0; i < edges.size(); i++ ){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            neigh[edges[i][0]]++;
            neigh[edges[i][1]]++;
        }
        queue<int> q;
        for( i = 0; i < n; i++ ){
            if( neigh[i] == 1 )q.push(i), neigh[i]--;
        }
        vector<int> ans;
        while( !q.empty() ){
            sz = q.size();
            ans.clear();
            for( i = 0; i < sz; i++ ){
                ans.push_back( q.front() );
                for( int ngh:adj[ q.front() ] ){
                    neigh[ngh]--;
                    if( neigh[ngh] == 1 )q.push( ngh );
                }
                q.pop();
            }
        }
        return ans;
    }
};
